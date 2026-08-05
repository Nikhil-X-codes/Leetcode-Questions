class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        int start = 0;
        int maxlen = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i + 1 <= 2 || dp[i + 1][j - 1]) {

                        dp[i][j] = true;

                        if (j - i + 1 > maxlen) {
                            maxlen = j - i + 1;
                            start = i;
                        }
                        
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};
