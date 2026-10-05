class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // score accumulated at the current depth

        for (char c : s) {
            if (c == '(') {
                st.push(0);  // start a new nested level with score 0 so far
            } else {
                int inner = st.top();
                st.pop();

                int score = (inner == 0) ? 1 : 2 * inner;

                st.top() += score;  // add this completed group's score to the level above
            }
        }

        return st.top();
    }
};