class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            
         bool isGood = true;

         if(i-k >= 0 and nums[i] <= nums[i-k]) isGood=false;

         if(i+k < n and nums[i] <= nums[i+k])  isGood=false;

        if(isGood) {
            sum+=nums[i];
        }

        }

        return sum;
    }
};
