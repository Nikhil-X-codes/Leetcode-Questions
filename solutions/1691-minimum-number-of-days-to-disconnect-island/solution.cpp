class Solution {
public:
    // Function to perform DFS and mark all connected land (1s) as visited
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int m, int n) {
        // Check for out-of-bounds or if the cell is water or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
            return;
        }
        
        vis[i][j] = true;  // Mark the cell as visited

        // Visit all 4 neighbors (up, down, left, right)
        dfs(grid, vis, i - 1, j, m, n);
        dfs(grid, vis, i + 1, j, m, n);
        dfs(grid, vis, i, j - 1, m, n);
        dfs(grid, vis, i, j + 1, m, n);
    }

    // Function to count the number of islands
    int noOfIslands(vector<vector<int>>& grid, int m, int n) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(grid, vis, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }

    // Main function to find the minimum number of days to disconnect the grid
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Check if the grid is already disconnected (number of islands != 1)
        if (noOfIslands(grid, m, n) != 1) {
            return 0;
        }

        // Try removing each land cell and check if the grid gets disconnected
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // Temporarily remove the land cell
                    if (noOfIslands(grid, m, n) != 1) {
                        return 1;  // If grid gets disconnected, return 1 day
                    }
                    grid[i][j] = 1;  // Restore the land cell
                }
            }
        }

        // If removing one cell doesn't work, return 2 (it will take at least 2 days)
        return 2;
    }
};

