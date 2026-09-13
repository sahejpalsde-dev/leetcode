class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;

        // Step 1: Collect coordinates of all 1s in both images using simple loops
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    v1.push_back({i, j});
                }
                if (img2[i][j] == 1) {
                    v2.push_back({i, j});
                }
            }
        }

        // 2D frequency matrix to track count of each shift vector (dr, dc)
        // Offset shift indices by (n - 1) to avoid negative indices
        vector<vector<int>> shiftCount(2 * n, vector<int>(2 * n, 0));
        int maxOverlap = 0;

        // Step 2: Compare every pair of 1s to record translation vectors
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                int dr = v2[j].first - v1[i].first + (n - 1);
                int dc = v2[j].second - v1[i].second + (n - 1);

                shiftCount[dr][dc]++;
                if (shiftCount[dr][dc] > maxOverlap) {
                    maxOverlap = shiftCount[dr][dc];
                }
            }
        }

        return maxOverlap;
    }
};