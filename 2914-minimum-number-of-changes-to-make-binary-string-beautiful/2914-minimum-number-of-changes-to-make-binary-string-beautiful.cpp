class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < (int)s.size(); i += 2)
            if (s[i] != s[i + 1]) changes++;          // a mixed pair needs one change
        return changes;
    }
};