class Solution {
public:
    
void solve(string digits, vector<string>&res,string s, int index){

        if(index >= digits.size()){
            res.push_back(s);
            return;
        }
      
unordered_map<int,string> mp = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};

int number=digits[index] - '0';
string value=mp[number];

for(int i=0;i<value.size();i++){
  s.push_back(value[i]);
  solve(digits,res,s,index+1);
  s.pop_back();
}

    }
    
    
vector<string> letterCombinations(string digits) {

        vector<string>res;
         string s="";
         int index=0;
        
        if(digits.size() == 0){
            return res;
        }
        
         solve(digits,res,s,index);
         return res;
    }
};
