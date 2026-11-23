class Solution {
    void dfs(vector<int>& nums, int index, vector<int>& cur,
             vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = index; i < (int)nums.size(); i++) {
            if ( i > index && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);
        return res;
    }
};