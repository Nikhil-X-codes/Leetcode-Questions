class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>mp;

        int maxi = *max_element(nums.begin(),nums.end());

        for(int i:nums){
            mp[i]++;
        }

        vector<int>score(maxi+1,0);

        for(auto &[e,c]:mp){
            score[e] = e*c;
        }

        vector<int>dp(maxi+1,0);

        dp[0] = 0;
        dp[1] = score[1];

        for(int i=2;i<=maxi;i++){
            dp[i] = max(dp[i-1],dp[i-2] + score[i]);
        } 

        return dp[maxi];
    }
};
