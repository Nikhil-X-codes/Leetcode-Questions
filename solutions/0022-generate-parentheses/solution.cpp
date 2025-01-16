class Solution {
public:
    
    void solve(vector<string>&res,int n,int open,int close,string ans){

      if(ans.size() == 2*n){
        res.push_back(ans);
        return;
      }
       
      if(open < n){
        solve(res,n,open+1,close,ans+'(');
      }

      if(close < open){
        solve(res,n,open,close+1,ans+')');
      }

    }
    
    
    vector<string> generateParenthesis(int n) {

      vector<string>res;
      string ans="";
      int open=0;
      int close=0;

      solve(res,n,open,close,ans);
      return res;
    }
};
