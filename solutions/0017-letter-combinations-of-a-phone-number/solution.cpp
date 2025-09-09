class Solution {
public:
    
    unordered_map<char,string>mp={
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(vector<string>&res,string &ans,string digits,int index){

        if(index >= digits.size()){
           res.push_back(ans);
           return;
        }

        char val=digits[index];
        string got=mp[val];

        for(int i=0;i<got.size();i++){
            
            ans.push_back(got[i]);
            solve(res,ans,digits,index+1);

            ans.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        
        vector<string>res;

        if(digits.empty()) return res;

        string ans="";

        solve(res,ans,digits,0);
        return res;
    }
};
