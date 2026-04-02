class Solution {
public:
    string frequencySort(string s) {
        
            unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }

         multimap<int, char,greater<int>> MM;

         for(auto &i:mp){
MM.insert({i.second,i.first});
         }
  
   string res = "";

   for(auto &p : MM){
            res.append(p.first, p.second); 
        }

        return res;
    }
};
