class Solution {
public:
   
    void solve(vector<int>candidates,vector<vector<int>>&output,vector<int>&res,int target,int index){
         
         if(target == 0){
            output.push_back(res);
            return;
         }

         if(index >= candidates.size() || candidates[index] > target) return;

         for(int i=index;i<candidates.size();i++){
             
            if(i > index && candidates[i] == candidates[i-1]) continue;
            
            res.push_back(candidates[i]);
            solve(candidates,output,res,target-candidates[i],i+1);

            res.pop_back();
         }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        vector<int>res;

        sort(candidates.begin(),candidates.end());
        solve(candidates,output,res,target,0);

        return output;
    }
};
