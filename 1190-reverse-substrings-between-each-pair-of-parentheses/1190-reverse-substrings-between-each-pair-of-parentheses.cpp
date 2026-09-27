class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair_idx(n, 0);
        vector<int> st;

        // Step 1: Precompute matching parenthesis indices using a stack
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push_back(i);
            } else if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                pair_idx[i] = j;
                pair_idx[j] = i;
            }
        }

        // Step 2: Traverse string and reverse directions at parenthesis portals
        string result = "";
        int i = 0;
        int direction = 1; // 1 = forward, -1 = backward

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair_idx[i];       // Jump to matching parenthesis
                direction = -direction; // Flip walking direction
            } else {
                result += s[i];
            }
            i += direction;
        }

        return result;
    }
};