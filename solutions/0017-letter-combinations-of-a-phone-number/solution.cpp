class Solution {
public:
   unordered_map<char,string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

   void solve(string digits, vector<string>&res,int index,int n,string &s){
     
    if(index >= n){
        res.push_back(s);
        return;
    }

        char ch = digits[index];      
        string val = keypad[ch]; 

    for(int i=0;i<val.size();i++){
        // include
        s.push_back(val[i]);
        solve(digits,res,index+1,n,s);

        // backtrack and exclude
        s.pop_back();
    }

   }

    vector<string> letterCombinations(string digits) {
        
        vector<string>res;
        int index=0;
        int n=digits.size();
        string s="";
        
        if(n == 0) return res;

        solve(digits,res,index,n,s);
       
        return res;
    }
};
