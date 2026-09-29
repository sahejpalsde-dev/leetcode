class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Total path length is m+n-1; a valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0) return false;

        // dp[i][j][b] = true if balance 'b' is achievable at cell (i,j)
        // Max possible balance at any cell is bounded by path length so far
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n));

        auto delta = [&](int i, int j) {
            return grid[i][j] == '(' ? 1 : -1;
        };

        // Base case: (0,0)
        dp[0][0] = vector<bool>(2, false);
        int b0 = delta(0, 0);
        if (b0 >= 0) dp[0][0][b0] = true;   // balance can't go negative

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int maxBalance = i + j + 2;  // upper bound for this cell's array size
                dp[i][j] = vector<bool>(maxBalance + 1, false);
                int d = delta(i, j);

                // Pull from top
                if (i > 0) {
                    for (int b = 0; b < (int)dp[i-1][j].size(); b++) {
                        if (dp[i-1][j][b]) {
                            int nb = b + d;
                            if (nb >= 0 && nb < (int)dp[i][j].size())
                                dp[i][j][nb] = true;
                        }
                    }
                }

                // Pull from left
                if (j > 0) {
                    for (int b = 0; b < (int)dp[i][j-1].size(); b++) {
                        if (dp[i][j-1][b]) {
                            int nb = b + d;
                            if (nb >= 0 && nb < (int)dp[i][j].size())
                                dp[i][j][nb] = true;
                        }
                    }
                }
            }
        }

        // At the destination, we need balance exactly 0 (all parens closed)
        return dp[m-1][n-1][0];
    }
};