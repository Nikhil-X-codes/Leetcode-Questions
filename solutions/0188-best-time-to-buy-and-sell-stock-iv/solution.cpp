class Solution {
public:
    int n;

    // int solve(int k, vector<int>& prices, int index, int buy) {

    //     // Base case
    //     if (index == n || k == 0)
    //         return 0;

    //     int profit = 0;

    //     // Can Buy
    //     if (buy == 1) {

    //         int take =
    //             -prices[index] +
    //             solve(k, prices, index + 1, 0);

    //         int not_take =
    //             solve(k, prices, index + 1, 1);

    //         profit = max(take, not_take);
    //     }

    //     // Can Sell
    //     else {

    //         int sell =
    //             prices[index] +
    //             solve(k - 1, prices, index + 1, 1);

    //         int skip =
    //             solve(k, prices, index + 1, 0);

    //         profit = max(sell, skip);
    //     }

    //     return profit;
    // }

    int maxProfit(int k, vector<int>& prices) {

        n = prices.size();

        // return solve(k, prices, 0, 1);

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {

            for (int cap = 1; cap <= k; cap++) {

                 dp[i][1][cap] = max(
                    -prices[i] + dp[i + 1][0][cap],
                    dp[i + 1][1][cap]
                );

                dp[i][0][cap] = max(
                    prices[i] + dp[i + 1][1][cap - 1],
                    dp[i + 1][0][cap]
                );
            }
        }

        return dp[0][1][k];
    }
};
