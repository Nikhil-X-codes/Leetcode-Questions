class Solution {
public:
    vector<vector<int>> memo;

    bool isPalindrome(string& s, int i, int j) {
        if (i >= j) return true;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) {
            memo[i][j] = isPalindrome(s, i + 1, j - 1);
        } else {
            memo[i][j] = false;
        }
        return memo[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        memo.assign(n, vector<int>(n, -1));

        int maxLen = 1, start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

