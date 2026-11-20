class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // Increment x to x + 1 using the existing run ending at x
            dp[x + 1] = dp[x] + 1;
            // Keep x as x using the existing run ending at x - 1
            dp[x] = dp[x - 1] + 1;

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};