class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(days.size() + 1);
        dp[days.size()]=0;

        for(int i=days.size()-1;i>=0;i--){

            int cost1 = costs[0] + dp[i+1];

        // 7-day pass
        int j = i;
        while (j < days.size() && days[j] <= days[i] + 6) {
            j++;
        }
        int cost7 = costs[1] + dp[j];

        // 30-day pass
        int k = i;
        while (k < days.size() && days[k] <= days[i] + 29) {
            k++;
        }
        int cost30 = costs[2] + dp[k];

        dp[i] = min(cost1, min(cost7, cost30));

        }
        
        return dp[0];
    }
};
