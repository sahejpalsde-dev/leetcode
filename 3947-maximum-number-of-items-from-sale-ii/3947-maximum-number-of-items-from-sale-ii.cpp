class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxF = 0, pm = INT_MAX;
        for (const auto& it : items) {
            maxF = max(maxF, it[0]);
            pm = min(pm, it[1]);
        }

        // mult[f] = number of items whose factor is a multiple of f
        vector<int> freq(maxF + 1, 0), mult(maxF + 1, 0);
        for (const auto& it : items) freq[it[0]]++;
        for (int f = 1; f <= maxF; f++) {
            if (!freq[f]) continue;
            for (int m = f; m <= maxF; m += f) mult[f] += freq[m];
        }

        // (price, d) pairs sorted by price
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {items[i][1], mult[items[i][0]] - 1};
        }
        sort(v.begin(), v.end());

        long long spent = 0, k = 0;
        long long ans = (long long)budget / pm; // k = 0 baseline

        for (const auto& [p, d] : v) {
            if (d <= 0) continue;

            long long max_affordable = (budget - spent) / p;
            long long buy = min((long long)d, max_affordable);

            if (buy > 0) {
                // Option A: Check buying 'buy' full copies at price p
                k += buy;
                spent += buy * p;
                ans = max(ans, 2 * k + (budget - spent) / pm);
            }

            // If we could not afford all 'd' copies, budget is exhausted for higher prices
            if (buy < d) break;
        }

        return (int)ans;
    }
};