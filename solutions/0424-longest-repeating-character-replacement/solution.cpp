
class Solution {
public:
    int characterReplacement(std::string s, int k) {

        int maxfreq = 0;
        int st = 0;
        int end = 0;
        int maxlen = 0;
        
      unordered_map<char, int> mp;

        while (end < s.length()) {
     
            mp[s[end]]++;
          
            maxfreq = std::max(maxfreq, mp[s[end]]);

            if ((end - st + 1) - maxfreq > k) {
                mp[s[st]]--;
                st++;        
            }

            maxlen = std::max(maxlen, end - st + 1);
            end++;
        }

        return maxlen;
    }
};

