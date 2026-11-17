class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = fewest changes to turn s[i..j] into a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {                 // length 1 can never be a semi-palindrome
                int L = j - i + 1;
                int best = INF;
                for (int d = 1; d < L; d++) {
                    if (L % d) continue;                      // d must divide the length
                    int c = 0, m = L / d;                     // m = size of each group
                    for (int r = 0; r < d; r++)               // group r: i+r, i+r+d, i+r+2d, ...
                        for (int a = 0; a < m / 2; a++)       // compare mirrored positions in the group
                            if (s[i + r + a * d] != s[i + r + (m - 1 - a) * d]) c++;
                    best = min(best, c);
                }
                cost[i][j] = best;
            }
        }

        // dp[t][j] = min changes to split the first j characters into t semi-palindromes
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int t = 1; t <= k; t++)
            for (int j = 1; j <= n; j++)
                for (int i = 0; i < j; i++)                   // last piece is s[i..j-1]
                    if (dp[t - 1][i] < INF && cost[i][j - 1] < INF)
                        dp[t][j] = min(dp[t][j], dp[t - 1][i] + cost[i][j - 1]);

        return dp[k][n];
    }
};