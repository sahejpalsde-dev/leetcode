class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;   // (right, left) so sorting is by right endpoint
        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;
            int i = first[c], j = last[c];
            bool ok = true;
            for (int k = i; k <= j; ++k) {
                int d = s[k] - 'a';
                if (first[d] < i) { ok = false; break; }
                j = max(j, last[d]);
            }
            if (ok) intervals.push_back({j, i});
        }

        sort(intervals.begin(), intervals.end());

        vector<string> res;
        int end = -1;
        for (auto &p : intervals) {
            int j = p.first, i = p.second;
            if (i > end) {
                res.push_back(s.substr(i, j - i + 1));
                end = j;
            }
        }
        return res;
    }
};