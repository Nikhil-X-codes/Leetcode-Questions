class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int sum=nums[0];
        int mini=INT_MAX;
        int mini1=INT_MAX;

        for(int i=1;i<nums.size();i++){

           if(nums[i] < mini){
            mini1=mini;
            mini=nums[i];
           }

           else if(nums[i] < mini1){
              mini1=nums[i];
           }

        }

        return sum+mini+mini1;
    }
};
