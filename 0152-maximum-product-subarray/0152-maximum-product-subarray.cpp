class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int pref = 1;
        int suff = 1;

        for (int i = 0; i < n; i++) {
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n - 1 - i];

            maxProd = max(maxProd, max(pref, suff));
        }

        return maxProd;
    }
};