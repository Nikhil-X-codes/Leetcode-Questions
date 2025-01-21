class Solution {
public:
   
   void solve( vector<vector<int>>&res,vector<int>& nums,int index){
   
     if(index >= nums.size()){
        res.push_back(nums);
        return;
     }

     for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);      
            solve(res, nums, index + 1);        
            swap(nums[index], nums[i]);  
     }
   }
   
    vector<vector<int>> permute(vector<int>& nums) {
        
         vector<vector<int>>res;
         int index=0;
         solve(res,nums,index);

         return res;
    }
};
