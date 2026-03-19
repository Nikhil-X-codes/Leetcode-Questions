class Solution {
public:
    // int solve(vector<vector<int>>& grid, int m, int n, int i, int j) {

    //     if (i >= m || j >= n)
    //         return INT_MAX;

    //     if (i == m - 1 && j == n - 1)
    //         return grid[i][j];

    //     int down = solve(grid, m, n, i + 1, j);
    //     int right = solve(grid, m, n, i, j + 1);

    //     return grid[i][j] + min(down, right);
    // }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(m ==1 && n == 1) return grid[0][0];
 
        // return solve(grid, m, n, 0, 0);

        vector<vector<int>>dp(m,vector<int>(n,0));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < m; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int j = 1; j < n; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i=1;i<m;i++){

            for(int j=1;j<n;j++){
               
               dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }

         return dp[m-1][n-1];
    }
};
