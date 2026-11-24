
class Solution {
public:

    bool solve(vector<vector<char>>& board, string word,
               int idx, int i, int j) {

        int n = board.size();
        int m = board[0].size();

        // Boundary condition
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }

        // Character does not match
        if(board[i][j] != word[idx]) {
            return false;
        }

        // Last character matched
        if(idx == word.size()-1) {
            return true;
        }

        // Store original character
        char ch = board[i][j];

        // Mark visited
        board[i][j] = '#';

        bool found = false;

        // Horizontal Left
        if(j > 0 && board[i][j-1] == word[idx+1]) {
            found = solve(board, word, idx+1, i, j-1);
        }

        // Horizontal Right
        if(!found && j < m-1 &&
           board[i][j+1] == word[idx+1]) {
            found = solve(board, word, idx+1, i, j+1);
        }

        // Vertical Up
        if(!found && i > 0 &&
           board[i-1][j] == word[idx+1]) {
            found = solve(board, word, idx+1, i-1, j);
        }

        // Vertical Down
        if(!found && i < n-1 &&
           board[i+1][j] == word[idx+1]) {
            found = solve(board, word, idx+1, i+1, j);
        }

        // Backtracking
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {

                    if(solve(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
