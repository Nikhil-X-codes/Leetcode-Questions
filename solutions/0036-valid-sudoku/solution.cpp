class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.find(board[i][j]) != rowSet.end())
                        return false;
                    rowSet.insert(board[i][j]);
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (colSet.find(board[i][j]) != colSet.end())
                        return false;
                    colSet.insert(board[i][j]);
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[blockRow*3 + i][blockCol*3 + j];
                        if (val != '.') {
                            if (boxSet.find(val) != boxSet.end())
                                return false;
                            boxSet.insert(val);
                        }
                    }
                }
            }
        }

        return true;
    }
};

