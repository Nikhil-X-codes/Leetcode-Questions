class Solution {
public:

    int solve(vector<int> nums, int val){

       int count=0;
       int len=0;

       for(int i=0;i<nums.size();i++){

         if(nums[i] <= val){
           len++;
         }
         else{
           len=0;
         }

         count+=len;
       }

       return count;
    }

int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
{
    return solve(nums,right)-solve(nums,left-1);
}

};
