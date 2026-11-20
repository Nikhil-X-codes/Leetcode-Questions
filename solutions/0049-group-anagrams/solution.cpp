class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>output;

        for(string s:strs){
          
          string key = s;
          sort(key.begin(),key.end());

          mp[key].push_back(s);
        }

        for(auto &i:mp){
            output.push_back(i.second);
        }

        return output;
    }
};
