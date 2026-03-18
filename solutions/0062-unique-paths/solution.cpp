class Solution {
public:
    // int solve(int m, int n, int i, int j){

    //    if(i == m-1 && j == n-1) return 1;

    //    if(i >= m || j >= n) return 0;

    //    int right = solve(m, n, i, j+1);
    //    int down  = solve(m, n, i+1, j);

    //    return right + down;
    // }

    int uniquePaths(int m, int n) {
        // return solve(m, n, 0, 0);
        
        if(m == 1 && n==1) return 1;

        vector<vector<int>> dp(m , vector<int>(n , 0));

        for (int i = 1; i < n; i++)
            dp[0][i] = 1;

        for (int i = 1; i < m; i++)
            dp[i][0] = 1;

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m-1][n-1];
    }
};
