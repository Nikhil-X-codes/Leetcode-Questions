class Solution {
public:
    
    int solve(vector<vector<int>>& grid,vector<vector<int>>&visited,int m,int n,int i,int j){
                
  if(i < 0 || i >= m || j < 0 || j >= n || 
           visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = 1;
          
        int gold = grid[i][j];
        
        int down  = solve(grid, visited, m, n, i+1, j);
        int up    = solve(grid, visited, m, n, i-1, j);
        int right = solve(grid, visited, m, n, i, j+1);
        int left  = solve(grid, visited, m, n, i, j-1);
    
        visited[i][j] = 0;

        return gold + max({down,up,right,left});
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int maxi=0;

        vector<vector<int>>visited(m,vector<int>(n,0));

          for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] != 0){
                    maxi = max(maxi, solve(grid, visited, m, n, i, j));
                }
            }
        }
        
        return maxi;
    }
};
