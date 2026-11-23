class Solution {
    void dfs(vector<int>& c, int start, int remaining,
             vector<int>& cur, vector<vector<int>>& res) {
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > remaining) break;
            if (i > start && c[i] == c[i - 1]) continue;
            cur.push_back(c[i]);
            dfs(c, i + 1, remaining - c[i], cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, 0, target, cur, res);
        return res;
    }
};