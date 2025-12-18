class Solution {
public:
    
    int solve(vector<int>& nums,int n,int start,int end,vector<int>& dp){

       dp[start]=nums[start];

       if(start+1 <= end){
       dp[start+1]=max(nums[start],nums[start+1]);
       }

      for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

       return dp[end];
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int>dp(n);

        int ans1=solve(nums,n,0,n-2,dp);
        int ans2=solve(nums,n,1,n-1,dp);

        return max(ans1,ans2);
    }
};
