class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // Mark the numbers that appear
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        // Find numbers that were never marked
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
