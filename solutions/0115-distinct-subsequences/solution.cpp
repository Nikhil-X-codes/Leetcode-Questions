class Solution {
public:
    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();

         vector<vector<long long>> dp(
            m + 1, vector<long long>(n + 1, 0)
        );

        dp[0][0] = 1;

        for(int i=1;i<=m;i++){
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == t[j - 1]) {
                   
                    if (dp[i - 1][j - 1] > INT_MAX - dp[i - 1][j])
                        dp[i][j] = INT_MAX;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }

                else {
                    dp[i][j] = dp[i-1][j];
                }

            }
        }

        return (int)dp[m][n];
    }
};
