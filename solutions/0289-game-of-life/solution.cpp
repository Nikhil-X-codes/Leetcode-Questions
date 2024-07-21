class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1}; 

        // First pass: determine the next state but mark changes using 2 (was 1, now 0) and 3 (was 0, now 1)
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;

                for (int k = 0; k < 8; k++) {
                    int curr_x = i + dx[k];
                    int curr_y = j + dy[k];

                    if (curr_x >= 0 && curr_x < m && curr_y >= 0 && curr_y < n && (board[curr_x][curr_y] == 1 || board[curr_x][curr_y] == 2)) {
                        liveNeighbors++;
                    }
                }

                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = 2; // Live to dead
                } else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 3; // Dead to live
                }
            }
        }

        // Second pass: finalize the state update
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0; // Marked as dead
                } else if (board[i][j] == 3) {
                    board[i][j] = 1; // Marked as live
                }
            }
        }
    }
};

