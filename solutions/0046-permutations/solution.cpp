class Solution {
public:

    void solve(vector<int> &nums,vector<vector<int>> &output,int index){

        if(index >= nums.size()){
        output.push_back(nums);
        return;
      }

        for(int i=index;i<nums.size();i++){

            swap(nums[i],nums[index]);
            solve(nums,output,index+1);
            
            swap(nums[i],nums[index]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> output;
        vector<int>res;
        
        solve(nums,output,0);

      return output;

    }
};
