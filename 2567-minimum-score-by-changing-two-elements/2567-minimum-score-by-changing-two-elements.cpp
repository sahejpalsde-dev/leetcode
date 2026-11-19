class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        int dropTwoSmallest = nums[n - 1] - nums[2];
        int dropBothEnds = nums[n - 2] - nums[1];
        int dropTwoLargest = nums[n - 3] - nums[0];

        return min({dropTwoSmallest, dropBothEnds, dropTwoLargest});
    }
};