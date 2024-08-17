class Solution {
public:
    bool isAnagram(string s, string t) {
        
       if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int>mp;

        for(char i:s){
            mp[i]++;
        } 

        for(char i:t){

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
