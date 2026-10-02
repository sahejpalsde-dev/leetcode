class Solution {
private:
    void backtrack(int n, int openCount, int closeCount, string current, vector<string>& result) {
        // Base case: string reaches length 2 * n
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Branch 1: Add '(' if we still have available opening brackets
        if (openCount < n) {
            backtrack(n, openCount + 1, closeCount, current + '(', result);
        }

        // Branch 2: Add ')' if closing count is less than open count
        if (closeCount < openCount) {
            backtrack(n, openCount, closeCount + 1, current + ')', result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};