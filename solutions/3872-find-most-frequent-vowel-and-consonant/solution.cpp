class Solution {
public:
    int maxFreqSum(string s) {
        
        unordered_set<char>st={'a','e','i','o','u'};
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
    
        for(char c:s){

           if(st.find(c) != st.end()){
             mp[c]++;
           }

           else{
            mp1[c]++;
           }

        }

        int maxVowelFreq = 0;
        if (!mp.empty()) {
            for (auto const& [key, val] : mp) {
                if (val > maxVowelFreq) {
                    maxVowelFreq = val;
                }
            }
        }

        int maxConsonantFreq = 0;
        if (!mp1.empty()) {
            for (auto const& [key, val] : mp1) {
                if (val > maxConsonantFreq) {
                    maxConsonantFreq = val;
                }
            }
        }

      return maxVowelFreq + maxConsonantFreq;
    }
};
