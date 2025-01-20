class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int index, int r, int c) {
    
        if (index >= word.size()) {
            return true;
        }

        int m = board.size(), n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool res = solve(board, word, index + 1, r + 1, c) ||
                   solve(board, word, index + 1, r - 1, c) ||
                   solve(board, word, index + 1, r, c + 1) ||
                   solve(board, word, index + 1, r, c - 1);

        board[r][c] = temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};

