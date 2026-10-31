class Solution {
private:
    int m, n;
    long long mod = 1e9 + 7;
    vector<vector<long long>> memo;

    // Simulate moving right from (r, c) with chain reflections
    pair<int, int> getNextRight(int r, int c, const vector<vector<int>>& grid) {
        int curr_r = r, curr_c = c + 1;
        int dir = 0; // 0 means moving right, 1 means moving down
        
        while (curr_r >= 0 && curr_r < m && curr_c >= 0 && curr_c < n) {
            if (grid[curr_r][curr_c] == 0) {
                return {curr_r, curr_c};
            }
            // Hit a mirror (1)
            if (dir == 0) {
                curr_r += 1;
                dir = 1;
            } else {
                curr_c += 1;
                dir = 0;
            }
        }
        return {-1, -1}; // Out of bounds
    }

    // Simulate moving down from (r, c) with chain reflections
    pair<int, int> getNextDown(int r, int c, const vector<vector<int>>& grid) {
        int curr_r = r + 1, curr_c = c;
        int dir = 1; // 1 means moving down, 0 means moving right
        
        while (curr_r >= 0 && curr_r < m && curr_c >= 0 && curr_c < n) {
            if (grid[curr_r][curr_c] == 0) {
                return {curr_r, curr_c};
            }
            // Hit a mirror (1)
            if (dir == 0) {
                curr_r += 1;
                dir = 1;
            } else {
                curr_c += 1;
                dir = 0;
            }
        }
        return {-1, -1}; // Out of bounds
    }

    long long dfs(int r, int c, const vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) return 1;
        if (memo[r][c] != -1) return memo[r][c];

        long long total_paths = 0;

        // Try moving Right
        auto next_right = getNextRight(r, c, grid);
        if (next_right.first != -1) {
            total_paths = (total_paths + dfs(next_right.first, next_right.second, grid)) % mod;
        }

        // Try moving Down
        auto next_down = getNextDown(r, c, grid);
        if (next_down.first != -1) {
            total_paths = (total_paths + dfs(next_down.first, next_down.second, grid)) % mod;
        }

        return memo[r][c] = total_paths;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // If the start or end cell itself is a mirror
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        memo.assign(m, vector<long long>(n, -1));
        return dfs(0, 0, grid);
    }
};