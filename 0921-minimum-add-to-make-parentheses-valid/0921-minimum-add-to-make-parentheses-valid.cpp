class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0; // Tracks unmatched '('
        int addCount = 0;  // Tracks unmatched ')' that require a '(' inserted

        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--; // Balance with a previous '('
                } else {
                    addCount++;  // Unmatched ')' found
                }
            }
        }

        return openCount + addCount;
    }
};