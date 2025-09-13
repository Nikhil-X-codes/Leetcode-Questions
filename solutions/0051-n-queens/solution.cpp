class Solution {
public:

    bool isvalid(int r, int c, vector<string>& board,int n) {

        for (int i = 0; i < c; i++) {
            if (board[r][i] == 'Q') return false;
        }

        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int c, vector<string>& board, vector<vector<string>>& res,int n) {
        if (c == n) {
            res.push_back(board); 
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isvalid(r, c, board,n)) {
                board[r][c] = 'Q';       // place queen
                solve(c + 1, board, res,n); // recurse for next column
                board[r][c] = '.';       // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); // initialize empty board
        solve(0, board, res,n);
        return res;
    }
};

