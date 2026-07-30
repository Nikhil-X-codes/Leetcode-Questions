class Solution {
public:

   void solve(int k,int n,vector<vector<int>> &output,vector<int>&res,int num){
        
        if(n == 0){
            if(res.size() == k){
                output.push_back(res);
                return;
            }
        }

        if(n < 0) return;

        for(int i=num;i<=9;i++){
            res.push_back(i);
            solve(k,n-i,output,res,i+1);
            res.pop_back();
        }
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> output;
        vector<int>res;

        solve(k,n,output,res,1);

        return output;
    }
};
