class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;                    // the increasing run grows
                dec = 1;                  // the decreasing run restarts
            } else if (nums[i] < nums[i - 1]) {
                dec++;                    // the decreasing run grows
                inc = 1;                  // the increasing run restarts
            } else {
                inc = dec = 1;            // equal neighbours break both runs
            }
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};