class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        vector<int> res;

        int n = board.size();

        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;

                int best = max({dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]});

                if (best == -1)
                    continue;

                long long count = 0;

                if (dp[i + 1][j] == best) {
                    count += ways[i + 1][j];
                }

                if (dp[i + 1][j + 1] == best) {
                    count += ways[i + 1][j + 1];
                }

                if (dp[i][j + 1] == best) {
                    count += ways[i][j + 1];
                }

                ways[i][j] = count % MOD;

                int value = 0;

                if (board[i][j] != 'E') {
                    value = board[i][j] - '0';
                }

                dp[i][j] = best + value;
            }
        }

        if (dp[0][0] == -1)
            return {0, 0};

        res.push_back(dp[0][0]);
        res.push_back(ways[0][0]);

        return res;
    }
};
