class Solution {
public:

    bool issafe(int c, int r, vector<vector<int>>& matrix, int n) {
        // Check row on left side
        for (int i = 0; i < c; i++) {
            if (matrix[r][i]) return false;
        }

        // Check upper diagonal on left side
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (matrix[i][j]) return false;
        }

        // Check lower diagonal on left side
        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (matrix[i][j]) return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& res, vector<vector<int>>& matrix, vector<string>& board, int n, int col) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (issafe(col, row, matrix, n)) {
                matrix[row][col] = 1;

                string s(n, '.');
                s[col] = 'Q';
                board[row] = s;

                solve(res, matrix, board, n, col + 1);

                // Backtrack
                matrix[row][col] = 0;
                board[row][col] = '.';
            }
        }
    }

    // Entry function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<string> board(n, string(n, '.'));

        solve(res, matrix, board, n, 0);
        return res;
    }
};

