class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        int maxi = m + n;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(maxi + 1, false)));

        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= maxi; balance++) {

                    if (grid[i][j] == '(') {

                        if ( i > 0 && balance > 0 && dp[i-1][j][balance-1]) {
                            dp[i][j][balance] = true;
                        }

                       if ( j > 0 && balance > 0 && dp[i][j-1][balance-1]) {
                            dp[i][j][balance] = true;
                        }

                    }

                    else {

                          if ( i > 0 && dp[i-1][j][balance+1]) {
                            dp[i][j][balance] = true;
                        }

                       if ( j > 0 && dp[i][j-1][balance+1]) {
                            dp[i][j][balance] = true;
                        }

                    }

                }

            }

        }

        return dp[m-1][n-1][0];
    }
};
