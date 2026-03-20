class Solution {
public:
    // int solve(vector<vector<int>>& triangle,int m,int n,int i,int j){

    //     if(i == m-1) return triangle[i][j];
    //     if(i < 0 || i >= m || j >=m || j < 0) return INT_MAX;

    //     int down = solve(triangle,m,n,i+1,j);
    //     int right = solve(triangle,m,n,i+1,j+1);

    //     return triangle[i][j] + min(down,right);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int n = triangle[0].size();

        if (m == 1 && n == 1)
            return triangle[0][0];

        //  return solve(triangle,m,n,0,0);

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = dp[i + 1][j];
                int right = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }

        return dp[0][0];
    }
};
