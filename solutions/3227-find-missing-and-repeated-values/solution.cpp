class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> res(2, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(grid[i][j]) - 1;
                int row = val / n;
                int col = val % n;

                if (grid[row][col] < 0) {
                    res[0] = abs(grid[i][j]);
                } else {
                    grid[row][col] = -grid[row][col];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int missingIndex = i * n + j + 1;
                    res[1] = missingIndex;
                }
            }
        }
        
        return res;
    }
};
