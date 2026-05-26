class Solution {
public:

    // int solve(vector<int>& prices, int index, int n, int buy) {

    //     if(index == n) return 0;

    //     int profit = 0;

    //     if(buy) {

    //         int take = -prices[index] + solve(prices, index + 1, n, 0);

    //         int skip = solve(prices, index + 1, n, 1);

    //         profit = max(take, skip);
    //     }
    //     else {

    //         int sell = prices[index] + solve(prices, index + 1, n, 1);

    //         int hold = solve(prices, index + 1, n, 0);

    //         profit = max(sell, hold);
    //     }

    //     return profit;
    // }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // return solve(prices, 0, n, 1);
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // dp[i][0] = not holding stock
        // dp[i][1] = holding stock

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i=1;i<=n;i++){
           
              dp[i][0] = max(
                dp[i-1][0],                 
                dp[i-1][1] + prices[i-1]   
            );

            dp[i][1] = max(
                dp[i-1][1],                 
                dp[i-1][0] - prices[i-1]   
            );

        }

        return dp[n][0];
    }
};
