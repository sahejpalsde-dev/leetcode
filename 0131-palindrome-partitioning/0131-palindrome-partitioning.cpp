class Solution {
    void dfs(const string& s, int start, vector<vector<bool>>& isPal,
             vector<string>& cur, vector<vector<string>>& res) {
        if (start == (int)s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < (int)s.size(); i++) {
            if (!isPal[start][i]) continue;
            cur.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, isPal, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                if (s[l] == s[r] && (r - l <= 2 || isPal[l + 1][r - 1])) {
                    isPal[l][r] = true;
                }
            }
        }
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, 0, isPal, cur, res);
        return res;
    }
};