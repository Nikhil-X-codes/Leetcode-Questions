class Solution {
public:
    // int solve(vector<vector<int>>& triangle, int m, int i, int j) {

    //     if (i == m - 1)
    //         return triangle[i][j];

    //     int same = solve(triangle, m, i + 1, j);
    //     int next = solve(triangle, m, i + 1, j + 1);

    //     return triangle[i][j] + min(same, next);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        // return solve(triangle, m, 0, 0);

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i--) {

            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};
