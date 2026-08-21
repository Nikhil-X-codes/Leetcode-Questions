class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1;i>=0;i--){

            for(int limit = 1;limit<=2;limit++){
                
dp[i][1][limit] = max(dp[i+1][1][limit],-prices[i]+dp[i+1][0][limit]);

dp[i][0][limit] = max(dp[i+1][0][limit],prices[i]+dp[i+1][1][limit-1]);

            }
        }

        return dp[0][1][2];
    }
};
