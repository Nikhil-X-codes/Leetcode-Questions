class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        if(totalsum % 2 != 0) return false;

        int target = totalsum / 2;

        vector<bool> prev(target+1,false);
        vector<bool> curr(target+1,false);

        prev[0] = true;

        for(int i = 1; i <= n; i++){

            curr[0] = true;

            for(int j = 1; j <= target; j++){

                bool include = false;

                if(nums[i-1] <= j){
                    include = prev[j - nums[i-1]];
                }

                bool exclude = prev[j];

                curr[j] = include || exclude;
            }

            prev = curr;
        }

        return prev[target];
    }
};
