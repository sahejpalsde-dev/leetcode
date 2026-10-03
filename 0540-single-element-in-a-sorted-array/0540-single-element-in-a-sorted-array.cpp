class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even, so mid and mid+1 form a "pair check"
            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                // Pair is intact — single element is after this pair
                low = mid + 2;
            } else {
                // Pair is broken — single element is at or before mid
                high = mid;
            }
        }

        return nums[low];
    }
};