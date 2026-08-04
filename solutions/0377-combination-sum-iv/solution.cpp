class Solution {
public:
    // int solve(int target,vector<int>& nums){

    //     if(target == 0) return 1;

    //     if(target < 0) return 0;

    //     int count=0;

    //     for(int i=0;i<nums.size();i++){
    //         count+=solve(target-nums[i],nums);
    //     }

    //     return count;
    // }

    int combinationSum4(vector<int>& nums, int target) {

        // return solve(target,nums);

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};
