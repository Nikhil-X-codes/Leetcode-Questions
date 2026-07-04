class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        vector<bool> dp(n + 1, false);

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                string word = s.substr(i, j - i + 1);

                if (st.find(word) != st.end() && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
