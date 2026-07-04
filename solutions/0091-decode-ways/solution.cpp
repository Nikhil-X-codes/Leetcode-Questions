class Solution {
public:
    // int solve(string& s, int n, int index) {

    //     if (index == n)
    //         return 1;

    //     if (s[0] == '0')
    //         return 0;

    //     int onedigit = solve(s, n, index + 1);

    //     int twodigit = 0;

    //     if (index + 1 < n) {

    //         int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

    //         if (num >= 10 && num <= 26) {
    //             twodigit = solve(s, n, index + 2);
    //         }
    //     }

    //     return onedigit + twodigit;
    // }

    int numDecodings(string s) {

        int n = s.size();

        // return solve(s, n, 0);

        vector<int>dp(n+1,0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '0') {
                dp[i] = 0;
            }

            else {

                dp[i] += dp[i + 1];

                if (i + 1 < n) {

                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                    if (num >= 10 && num <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};
