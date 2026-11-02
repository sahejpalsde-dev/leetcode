class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());   // median ends up at index n/2
        int median = nums[n / 2];

        long long moves = 0;
        for (int x : nums) moves += abs(x - median);
        return (int)moves;
    }
};
