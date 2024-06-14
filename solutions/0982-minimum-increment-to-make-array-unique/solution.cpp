class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end()); 

        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1] >= nums[i]){
                count+=nums[i-1] - nums[i] +1;
                nums[i] = nums[i-1] +1;
            }
        }
        return count;
    }
};
