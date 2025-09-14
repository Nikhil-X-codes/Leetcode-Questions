#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isvalid(int r, int c, vector<string>& board, int n) {
        // check left side of row
        for (int i = 0; i < c; i++) {
            if (board[r][i] == 'Q') return false;
        }
        // check upper-left diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // check lower-left diagonal
        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    // backtracking function
    int solve(int c, vector<string>& board, vector<vector<string>>& res, int n) {
        if (c == n) {
            res.push_back(board); // store valid board config
            return 1;             // found 1 valid solution
        }

        int count = 0;
        for (int r = 0; r < n; r++) {
            if (isvalid(r, c, board, n)) {
                board[r][c] = 'Q';                  // place queen
                count += solve(c + 1, board, res, n); // recurse
                board[r][c] = '.';                  // backtrack
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); 
        return solve(0, board, res, n);
    }
};

