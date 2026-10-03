class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // sentinel base for length calculations
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // push index of '('
            } else {
                st.pop();  // try to match with the last unmatched '(' or sentinel

                if (st.empty()) {
                    // no matching '(' available — this ')' breaks the chain
                    st.push(i);  // this becomes the new base
                } else {
                    // valid substring found; measure its length
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};