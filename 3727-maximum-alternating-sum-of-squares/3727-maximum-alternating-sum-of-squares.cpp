class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++)
            sq[i] = 1LL * nums[i] * nums[i];     // only the squares matter

        sort(sq.begin(), sq.end());              // ascending

        int minus = n / 2;                       // number of subtracted positions
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < minus) ans -= sq[i];         // smallest squares are subtracted
            else           ans += sq[i];         // largest squares are added
        }
        return ans;
    }
};