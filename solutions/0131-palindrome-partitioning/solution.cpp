class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) return false;
        start++; end--;
    }
    return true;
}

    void solve(vector<vector<string>>&output,vector<string>&res,int index,string &s){
          
        if(index == s.size()){
            output.push_back(res);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                res.push_back(s.substr(index, i - index + 1));
                solve(output,res,i + 1,s);
                res.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>output;
        vector<string>res;
          
        solve(output,res,0,s);
        return output;
    }
};
