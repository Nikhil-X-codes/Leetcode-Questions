class Solution {
public:

    void solve(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
        
        int n = grid.size();
        int m = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m || 
            visited[x][y] || grid[x][y] == '0') 
            return;

        visited[x][y] = true;

        solve(grid, x+1, y, visited);
        solve(grid, x-1, y, visited);
        solve(grid, x, y+1, visited);
        solve(grid, x, y-1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    solve(grid, i, j, visited);  
                }
            }
        }

        return count;
    }
};

