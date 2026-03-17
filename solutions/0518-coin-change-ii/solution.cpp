class Solution {
public:
    // int solve(int amount, vector<int>& coins,int index){

    //     if(amount == 0) return 1;
    //     if(amount < 0) return 0;
    //     if(index >= coins.size()) return 0;

    //     return
    //     solve(amount-coins[index],coins,index)+solve(amount,coins,index+1);
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // return solve(amount,coins,0);

        // vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        // for(int i=0;i<=n;i++) dp[i][0] = 1;

        // for(int i=1;i<=n;i++){

        //     for(int j=1;j<=amount;j++){

        //         if(coins[i-1] <= j){
        //             dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        //         }

        //         else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }

        // return dp[n][amount];

        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;

            for (int j = 1; j <= amount; j++) {

                long long include = 0;

                if (coins[i - 1] <= j) {
                    include = curr[j - coins[i - 1]];
                }

                long long exclude = prev[j];

                curr[j] = include + exclude;
            }

            prev = curr;
        }

        return prev[amount];

    }
};
