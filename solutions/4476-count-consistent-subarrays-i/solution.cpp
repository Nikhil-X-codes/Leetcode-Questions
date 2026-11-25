class Solution {
public:
    int countConsistent(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int mini = nums[i];
            int bitAnd = nums[i];

            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
                bitAnd &= nums[j];

                if (bitAnd == mini)
                    count++;
            }
            
        }

        return count;
    }
};
