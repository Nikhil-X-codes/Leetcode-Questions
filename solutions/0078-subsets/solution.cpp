class Solution {
public:

   void solve( vector<vector<int>>& output,vector<int>& res,vector<int> nums,int index,int n){
      
    if(index >= n){
        output.push_back(res);
        return;
    }
    
// include
    int element=nums[index];
    res.push_back(element);

    solve(output,res,nums,index+1,n);
  
  // exclude
    res.pop_back();
    solve(output,res,nums,index+1,n);

   }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>output;
        vector<int>res;
        int index=0;
        int n=nums.size();

        solve(output,res,nums,index,n);

        return output;
    }
};
