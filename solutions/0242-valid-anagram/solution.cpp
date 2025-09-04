class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        unordered_map<char,int>mp;

        for(char c:s) mp[c]++;

        for(int i:t){
            if(mp[i] > 0){
                mp[i]--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
