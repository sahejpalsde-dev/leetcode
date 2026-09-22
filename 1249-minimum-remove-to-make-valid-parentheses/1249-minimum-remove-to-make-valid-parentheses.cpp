
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string sb = "";
        int n = s.length();
        int extraOpen = 0;

        // remove all invalid closing brackets
        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (ch == '(') {
                extraOpen++;
                sb += ch;
            }
            else if (ch == ')') {

                if (extraOpen == 0) {
                    continue;
                }

                extraOpen--;
                sb += ch;
            }
            else {
                sb += ch;
            }
        }

        // remove the extra open brackets
        n = sb.length();

        for (int i = n - 1; i >= 0; i--) {

            if (extraOpen == 0) {
                break;
            }

            char ch = sb[i];

            if (ch == '(') {
                sb.erase(i, 1);
                extraOpen--;
            }
        }

        return sb;
    }
};