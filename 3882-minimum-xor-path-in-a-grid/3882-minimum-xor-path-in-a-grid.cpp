class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // reach[i][j][v] = true if some path from (0,0) to (i,j) has XOR exactly v
        vector<vector<bitset<1024>>> reach(m, vector<bitset<1024>>(n));
        reach[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<1024> from;                         // XORs available before entering (i,j)
                if (i > 0) from |= reach[i - 1][j];
                if (j > 0) from |= reach[i][j - 1];

                for (int v = 0; v < 1024; v++)
                    if (from[v]) reach[i][j][v ^ grid[i][j]] = true;
            }
        }

        for (int v = 0; v < 1024; v++)                     // smallest reachable XOR at the end
            if (reach[m - 1][n - 1][v]) return v;
        return -1;                                         // not reachable in practice
    }
};