class Solution {
public:

   void solve(vector<vector<int>>&output,vector<int>&res,vector<int>nums,int index,int n){

    output.push_back(res);
    
    for(int i=index;i<n;i++){

        if(i > index && nums[i] == nums[i-1]) continue;
        
        res.push_back(nums[i]);
        solve(output,res,nums,i+1,n);

        // backtrack
        res.pop_back();

    }

   }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
         vector<vector<int>>output;
         vector<int>res;
         int index=0;
         int n=nums.size();
         
         sort(nums.begin(),nums.end());
         solve(output,res,nums,index,n);
         return output;
    }
};
