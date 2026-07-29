class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int maxi = nums[0];
        int mini = nums[0];
        int maxisum = nums[0];
        int minisum = nums[0];

        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 1; i < nums.size(); i++) {
            maxi = max(nums[i], maxi + nums[i]);
            mini = min(nums[i], mini + nums[i]);

            maxisum = max(maxisum, maxi);
            minisum = min(minisum, mini);
        }

        if (maxisum < 0)
            return maxisum;
            
        return max(maxisum, totalsum - minisum);
    }
};
