class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);

        // dp[r] stores the frequency of subarrays ending at current position with product % k == r
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> next_dp(k, 0);
            int val = nums[i] % k;

            // 1. Extend existing subarrays from previous index
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int next_rem = (r * val) % k;
                    next_dp[next_rem] += dp[r];
                }
            }

            // 2. Single-element subarray starting at index i
            next_dp[val]++;

            // 3. Add current end-position subarray remainders to final result
            for (int r = 0; r < k; r++) {
                result[r] += next_dp[r];
            }

            // Move to next position
            dp = move(next_dp);
        }

        return result;
    }
};