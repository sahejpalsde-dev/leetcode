class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int pm = INT_MAX;
        for (auto& it : items) pm = min(pm, it[1]);

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int g = 1;
            for (int j = 0; j < n; j++)
                if (j != i && items[j][0] % items[i][0] == 0) g++;
            int p = items[i][1];
            for (int b = budget; b >= p; b--)
                dp[b] = max(dp[b], dp[b - p] + g);
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = max(ans, dp[b] + (budget - b) / pm);
        return ans;
    }
};