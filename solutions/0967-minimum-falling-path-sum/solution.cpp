class Solution {
public:
    //    int solve(vector<vector<int>>& matrix,int m,int n,int i,int j){
    //     if(i >= m || j >= n || j < 0 || i < 0) return INT_MAX;

    //     if(i == m-1) return matrix[i][j];

    //     int left = solve(matrix,m,n,i+1,j-1);
    //     int down = solve(matrix,m,n,i+1,j);
    //     int right = solve(matrix,m,n,i+1,j+1);

    //     return matrix[i][j] + min({left,down,right});
    //    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        //     int mini = INT_MAX;

        //     for(int j=0;j<n;j++){
        //    mini = min(mini,solve(matrix,m,n,0,j));
        //     }

        //     return mini;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (m == 1 && n == 1)
            return matrix[0][0];

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int down = dp[i - 1][j];
                int left = j > 0 ? dp[i - 1][j -1] : INT_MAX;
                int right = (j < n-1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({down, left, right});
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};
