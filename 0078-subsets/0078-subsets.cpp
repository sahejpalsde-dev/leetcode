
class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        // Base condition
        if(index == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Pick the element
        ds.push_back(nums[index]);
        solve(index + 1, nums, ds, ans);

        // Backtrack (remove last element)
        ds.pop_back();

        // Not pick the element
        solve(index + 1, nums, ds, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};
