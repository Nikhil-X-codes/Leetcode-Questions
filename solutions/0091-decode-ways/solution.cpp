class Solution {
public:
    int solve(string& s, int index) {

        if (index >= s.size())
            return 1;

        int onedigit = solve(s, index + 1);

        int twodigit = 0;

        if (index + 1 < s.size()) {

            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (num >= 10 && num <= 26) {
                twodigit = solve(s, index + 2);
            }
        }

        return onedigit + twodigit;
    }

    int numDecodings(string s) {

        if (s[0] == '0')
            return 0;

        int n = s.size();

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
