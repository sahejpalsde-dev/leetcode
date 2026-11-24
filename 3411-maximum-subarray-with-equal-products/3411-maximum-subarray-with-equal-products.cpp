class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > 25200) break;   // lcm * gcd can never reach this
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod == l * g) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};