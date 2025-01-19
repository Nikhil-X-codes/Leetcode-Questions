class Solution {
public:
   
   void solve(int k, int n,vector<vector<int>>&output,vector<int>&res,int sum,int index){
    
       if (res.size() == k) {

            if (sum == n) {
                output.push_back(res);
            }
            
            return;
        }

    for(int i=index;i<=9;i++){

        if(sum + i > n){
            break;
        }

        res.push_back(i);
        solve(k,n,output,res,sum+i,i+1);
        res.pop_back();
    }

   }
   
   
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>output;
        vector<int>res;
        int sum=0;
        int index=1;

        solve(k,n,output,res,sum,index);

        return output;
    }
};
