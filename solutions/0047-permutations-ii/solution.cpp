class Solution {
public:
    
    void solve(vector<int>&nums,vector<vector<int>>&res,int index){

        if(index == nums.size()){
                 res.push_back(nums);
        return;
        }

        unordered_set<int>s;

        for(int i=index;i<nums.size();i++){
              
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);

            swap(nums[i],nums[index]);
            solve(nums,res,index+1);

            swap(nums[i],nums[index]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
       
       solve(nums,res,0);

        return res;
    }
};
