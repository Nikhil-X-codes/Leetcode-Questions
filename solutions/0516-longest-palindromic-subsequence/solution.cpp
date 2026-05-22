class Solution {
public:
    int m, n;

    // int solve(string &text1, string &text2, int i, int j) {

    //     if (i >= m || j >= n)
    //         return 0;

    //     if (text1[i] == text2[j]) {
    //         return 1 + solve(text1, text2, i + 1, j + 1);
    //     }

    //     return max(
    //         solve(text1, text2, i, j + 1),
    //         solve(text1, text2, i + 1, j)
    //     );
    // }

    int longestPalindromeSubseq(string s) {

        string s1 = s;
        reverse(s1.begin(), s1.end());

        m = s.size();
        n = s1.size();

        // return solve(s, s1, 0, 0);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == s1[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
