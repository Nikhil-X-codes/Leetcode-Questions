class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n=s.size();

      if(n < k) return false;

      unordered_map<char,int>mp;

      for(char c:s){
        mp[c]++;
      }
        
      int oddcount=0;

      for(auto i:mp){

         if(i.second % 2 != 0){
          oddcount++;
         }

      }

      if(oddcount > k) return false;


return true;
    }
};
