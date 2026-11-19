class Solution {
    void dfs(vector<int>& c, int start, int remain, vector<int>& path, vector<vector<int>>& ans) {
        if (remain == 0) {                         // exact sum reached: save this combination
            ans.push_back(path);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > remain) break;              // sorted, so every later value is too big as well
            path.push_back(c[i]);                  // choose c[i]
            dfs(c, i, remain - c[i], path, ans);   // stay at i: the same number may be reused
            path.pop_back();                       // undo the choice
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates, 0, target, path, ans);
        return ans;
    }
};