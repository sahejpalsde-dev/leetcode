class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;    // insertions made so far
        int need = 0;   // ')' still required by the '(' seen so far

        for (char c : s) {
            if (c == '(') {
                need += 2;                 // each '(' needs two ')'
                if (need % 2 == 1) {       // previous '(' has only one ')' so far
                    ans++;                 // insert a ')' to complete it
                    need--;
                }
            } else {
                need--;                    // this ')' covers one needed ')'
                if (need < 0) {            // no '(' to match: insert a '('
                    ans++;
                    need = 1;              // the new '(' still needs one more ')'
                }
            }
        }
        return ans + need;                 // append the ')' still missing
    }
};