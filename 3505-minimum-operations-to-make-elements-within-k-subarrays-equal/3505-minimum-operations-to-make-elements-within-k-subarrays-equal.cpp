class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int W = n - x + 1;                          // number of windows
        vector<long long> cost(W);

        multiset<long long> lo, hi;                 // lo = smaller half (size ceil), hi = larger half
        long long sLo = 0, sHi = 0;
        auto rebalance = [&]() {
            int sz = lo.size() + hi.size();
            while ((int)lo.size() > (sz + 1) / 2) {
                auto it = prev(lo.end());
                sLo -= *it; sHi += *it;
                hi.insert(*it); lo.erase(it);
            }
            while ((int)lo.size() < (sz + 1) / 2) {
                auto it = hi.begin();
                sHi -= *it; sLo += *it;
                lo.insert(*it); hi.erase(it);
            }
        };
        auto add = [&](long long v) {
            if (lo.empty() || v <= *lo.rbegin()) { lo.insert(v); sLo += v; }
            else { hi.insert(v); sHi += v; }
            rebalance();
        };
        auto del = [&](long long v) {
            if (v <= *lo.rbegin()) { lo.erase(lo.find(v)); sLo -= v; }
            else { hi.erase(hi.find(v)); sHi -= v; }
            rebalance();
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) del(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sLo + sHi - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        // dp[j][i] = min cost using the first i elements with j chosen windows
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];                         // skip element i-1
                if (i >= x && dp[j - 1][i - x] < INF)            // window ends at i-1
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};