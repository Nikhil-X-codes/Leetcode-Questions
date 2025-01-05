class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
      vector<vector<string>>res;

      unordered_map<string,vector<string>>mp;

      for(auto &i:strs){
        string sorted = i;
        sort(sorted.begin(), sorted.end()); 
        mp[sorted].push_back(i);
      }

      for(auto &iterator:mp){
        res.push_back(iterator.second);
      }
            
return res;
    }
};
