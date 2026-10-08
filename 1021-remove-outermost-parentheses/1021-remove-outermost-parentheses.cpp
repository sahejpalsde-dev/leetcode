class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int prev = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                if (prev > 0) {
                    ans += s[i];
                }

                prev++;
            }

            else {

                prev--;

                if (prev > 0) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};