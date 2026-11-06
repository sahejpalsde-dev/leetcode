class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // sort logs by time
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) { return a[1] < b[1]; });

        // process queries in increasing order, remembering original positions
        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        vector<int> cnt(n + 1, 0), ans(q);
        int active = 0;                                   // servers with at least one request in the window
        int l = 0, r = 0, m = logs.size();

        for (int idx : order) {
            int hi = queries[idx], lo = hi - x;           // window [lo, hi]

            while (r < m && logs[r][1] <= hi) {           // add requests up to time hi
                if (cnt[logs[r][0]]++ == 0) active++;
                r++;
            }
            while (l < r && logs[l][1] < lo) {            // drop requests before time lo
                if (--cnt[logs[l][0]] == 0) active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};