class Solution {
public:
    
    void solve(vector<int>& nums, int target,int index,int sum,int &count){
      
      if(index >= nums.size()){

      if(sum == target){
        count++;
      }

      return;
      }

        solve(nums, target, index + 1, sum + nums[index], count);
        solve(nums, target, index + 1, sum - nums[index], count);
      
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int index=0;
        int sum=0;
        int count=0;

        solve(nums,target,index,sum,count);
        return count;
    }
};
