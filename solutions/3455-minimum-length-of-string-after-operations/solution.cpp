class Solution {
public:
    int minimumLength(string s) {
        
      int n=s.size();

      unordered_map<char,int>mp;

      int res=0;

      for(char i:s){
        mp[i]++;
      }

      for(const auto &pair : mp){

        if(pair.second % 2 != 0){
          res+=1;
        }
        
        else{
         res+=2;
        }

      }
return res;
    }
};
