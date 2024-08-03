class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Directions array to check all 8 neighbors
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        // Iterate over each cell
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int liveCounts = 0;

                // Check all 8 neighbors
                for(int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    // Check if neighbor is within bounds and if it is alive (1 or 2)
                    if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        liveCounts++;
                    }
                }

                // Apply the rules of the game
                if(board[i][j] == 1) {
                    if(liveCounts < 2 || liveCounts > 3) {
                        board[i][j] = 2; // Mark cell as dead (temporarily marked as 2)
                    }
                } else {
                    if(liveCounts == 3) {
                        board[i][j] = 3; // Mark cell as alive (temporarily marked as 3)
                    }
                }
            }
        }

        // Update the board to the new state
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 2) {
                    board[i][j] = 0; // Dead cell
                } else if(board[i][j] == 3) {
                    board[i][j] = 1; // Alive cell
                }
            }
        }
    }
};

