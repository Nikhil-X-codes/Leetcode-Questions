class Solution {
public:
    // int solve(vector<vector<int>>& obstacleGrid,int m,int n,int x,int y){

    //    if(x < 0 || x >= m || y < 0 || y >= n || obstacleGrid[x][y] == 1)
    //    return 0;

    //          if(x == m-1 && y == n-1) return 1;

    //     int down = solve(obstacleGrid,m,n,x+1,y);
    //    int right = solve(obstacleGrid,m,n,x,y+1);

    //    return down+right;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // return solve(obstacleGrid,m,n,0,0);

        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
