class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX / 4);
        dp[0] = 0;                                        // start at step 0 with cost 0

        for (int j = 1; j <= n; j++) {
            for (int d = 1; d <= 3 && j - d >= 0; d++) {  // arrive from step j-1, j-2 or j-3
                dp[j] = min(dp[j], dp[j - d] + costs[j - 1] + (long long)d * d);
            }
        }
        return (int)dp[n];
    }
};