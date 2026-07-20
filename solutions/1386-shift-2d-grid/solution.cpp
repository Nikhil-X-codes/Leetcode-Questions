class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        for (int shift = 0; shift < k; shift++) {

            vector<vector<int>> temp(m, vector<int>(n));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (j < n - 1) {
                        temp[i][j + 1] = grid[i][j];
                    }
                    else if (i < m - 1) {
                        temp[i + 1][0] = grid[i][j];
                    }
                    else {
                        temp[0][0] = grid[i][j];
                    }
                }
            }

            grid = temp;
        }

        return grid;
    }
};
