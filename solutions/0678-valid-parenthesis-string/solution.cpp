class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i < n; i++) {

            for (int bal = 0; bal <= n; bal++) {

                if (!dp[i][bal])
                    continue;

                if (s[i] == '(') {
                    dp[i + 1][bal + 1] = true;
                }

                else if (s[i] == ')') {
                    if (bal > 0)
                        dp[i + 1][bal - 1] = true;
                }

                else {

                    dp[i + 1][bal + 1] = true;

                    dp[i + 1][bal] = true;

                    if (bal > 0) {
                        dp[i + 1][bal - 1] = true;
                    }
                }

            }
        }

        return dp[n][0];
    }
};
