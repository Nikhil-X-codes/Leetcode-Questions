class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        	string text1 = s;
		string text2 = s;
		reverse(text2.begin(), text2.end());
		
		int m = text1.size();
		int n = text2.size();
		
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				
				if (text1[i] == text2[j]) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}
		
		return dp[0][0];
		
    }
};
