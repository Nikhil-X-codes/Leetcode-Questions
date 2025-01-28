class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char,int>mp;

        for(char ch:s){
            mp[ch]++;
        }

        for(char i:t){

            if(mp[i] == 0){
             return i;
            }

            mp[i]--;

        }

      return '\0';
    }
};
