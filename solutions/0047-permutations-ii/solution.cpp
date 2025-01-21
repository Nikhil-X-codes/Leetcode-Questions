class Solution {
public:
    
    void solve( vector<vector<int>>&res,vector<int>& nums,int index){
   
     if(index >= nums.size()){
        res.push_back(nums);
        return;
     }
       
    unordered_set<int> seen;

     for(int i=index;i<nums.size();i++){
            
            if(seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[index], nums[i]);      
            solve(res, nums, index + 1);        
            swap(nums[index], nums[i]);  
     }

   }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

       vector<vector<int>>res;
       int index=0;
       sort(nums.begin(),nums.end());

       solve(res,nums,index);
       return res;

    }
};
