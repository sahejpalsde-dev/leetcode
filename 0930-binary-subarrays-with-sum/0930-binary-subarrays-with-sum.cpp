class Solution {
private:
    // Helper function to count subarrays with sum AT MOST target
    int atMost(vector<int>& nums, int target) {
        if (target < 0) return 0;

        int left = 0;
        int count = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Shrink window from the left if sum exceeds target
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at 'right' starting between 'left' and 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Subarrays with sum EXACTLY goal = atMost(goal) - atMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};