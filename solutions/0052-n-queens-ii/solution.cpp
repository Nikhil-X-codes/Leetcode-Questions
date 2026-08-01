class Solution {
public:
    bool isValid(vector<string>& board, int row, int col, int n) {

        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    int solve(vector<vector<string>>& ans, vector<string>& board, int n,
              int col) {

        if (col == n) {
            ans.push_back(board);
            return 1;
        }

        int count = 0;

        for (int row = 0; row < n; row++) {

            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                count += solve(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }

        return count;
    }

    int totalNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        return solve(ans, board, n, 0);
    }
};
