class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);    // it can store multiple value instead of mp[key] = s
        }

        vector<vector<string>>res;

        for(auto &entry:mp){
            res.push_back(entry.second);
        }

        return res;
    }
};
