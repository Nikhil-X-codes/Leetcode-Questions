class Solution {
public:
    void solve(vector<vector<int>>&output,vector<int>&res,vector<int>candidates,int target,int index){

        if(target == 0){
            output.push_back(res);
            return;
        }
        
        if(index >= candidates.size() || candidates[index] > target) 
            return;
        
        res.push_back(candidates[index]);
        solve(output,res,candidates,target-candidates[index],index);

        res.pop_back();
        solve(output,res,candidates,target,index+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        vector<int>res;
        int index=0;
        
        sort(candidates.begin(),candidates.end());
        solve(output,res,candidates,target,index);
        
        return output;
    }
};
