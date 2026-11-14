class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);                        // pre[i] = sum of the first i elements
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                int sum = pre[i + len] - pre[i];          // sum of nums[i .. i+len-1]
                if (sum > 0) ans = min(ans, sum);         // only positive sums count
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};