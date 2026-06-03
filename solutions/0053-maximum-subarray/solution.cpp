class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currsum = nums[0];
        int maxsum = nums[0];

        int n = nums.size();

        for (int i = 1; i < n; i++) {
            currsum = max(nums[i], currsum + nums[i]);
            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
};
