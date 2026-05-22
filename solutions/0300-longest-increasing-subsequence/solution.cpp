class Solution {
public:
    //     int solve(int index,int previndex,vector<int>& nums){

    //         if(index == nums.size()){
    // return 0;
    //         }

    //         int nottake = solve(index+1,previndex,nums);

    //          int take = 0;

    //         if(previndex != -1 || nums[index] > nums[previndex]){
    //            take = 1+solve(index+1,index,nums);
    //         }

    //        return max(take,nottake);
    //     }

    int lengthOfLIS(vector<int>& nums) {

        // return solve(0,-1,nums);

        int n = nums.size();

        vector<int> dp(n,1);

        int maxi = 1;

        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {

                if (nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
