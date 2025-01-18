class Solution {
public:
   
   void solve(vector<int>& candidates, int target,vector<vector<int>>&output,vector<int>&res,int index,int sum){

    if(sum == target){
        output.push_back(res);
        return;
    }

    if(sum > target){
        return;
    }

    for(int i=index;i<candidates.size();i++){

        if(i>index and candidates[i] == candidates[i-1]) continue;
        res.push_back(candidates[i]);
        solve(candidates,target,output,res,i+1,sum+candidates[i]);
        res.pop_back();

    }


   }
   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
         vector<vector<int>>output;
         vector<int>res;
         int index=0;
         int sum=0;

         sort(candidates.begin(),candidates.end());

         solve(candidates,target,output,res,index,sum);

         return output;

    }
};
