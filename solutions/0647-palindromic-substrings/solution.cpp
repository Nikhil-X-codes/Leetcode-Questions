class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
