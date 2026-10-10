class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;   // moves on either array both shrink |diff| by 1

        int mx = 0;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, d[i]);
        }

        // cnt[v] = number of positions whose difference is currently v
        vector<long long> cnt(mx + 1, 0);
        for (int x : d) cnt[x]++;

        // lower the highest level first
        for (int v = mx; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            if (k >= cnt[v]) {              // lower the whole level by 1
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {                        // budget covers only part of the level
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long v = 1; v <= mx; v++) ans += cnt[v] * v * v;
        return ans;
    }
};