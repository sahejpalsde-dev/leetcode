class Solution {
private:
    // Helper function to count subarrays with AT MOST k odd numbers
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int count = 0;
        int oddCount = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // Shrink window if number of odd elements exceeds k
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // Number of valid subarrays ending at 'right' is equal to window length
            count += (right - left + 1);
        }

        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Subarrays with exactly k odd numbers = atMost(k) - atMost(k - 1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};