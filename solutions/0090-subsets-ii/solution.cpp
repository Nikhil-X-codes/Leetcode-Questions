class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& output, vector<int>& res, int index){
         
        output.push_back(res);

        for(int i=index;i<nums.size();i++){
          
          if(i > index && nums[i] == nums[i-1]) continue;

          res.push_back(nums[i]);
          solve(nums,output,res,i+1);

          res.pop_back();
        }

          
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>>output;
        vector<int>res;

        solve(nums,output,res,0);

        return output;
    }
};
