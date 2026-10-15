class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> seen(101, false);      // values are at most 100
            int distinct = 0;
            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {           // a new value joins the subarray
                    seen[nums[j]] = true;
                    distinct++;
                }
                ans += distinct * distinct;     // add the square for nums[i..j]
            }
        }
        return ans;
    }
};