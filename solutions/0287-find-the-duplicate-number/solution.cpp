class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0;i<n;i++){

            int element = abs(nums[i]);
            int idx = element-1;

            if(nums[idx] < 0){
return element;
            }

            nums[idx] = - nums[idx];
        }

        return -1;
    }
};
