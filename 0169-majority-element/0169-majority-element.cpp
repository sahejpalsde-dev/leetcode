class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int same = nums[0];
        int count = 0;
        int ans = nums[0];
        int val = nums.size() / 2;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == same) {
                count++;
            } 
            else {
                same = nums[i]; // Fixed assignment operator
                count = 1;      // Count starts at 1 for the new element
            }

            if (count > val) {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};