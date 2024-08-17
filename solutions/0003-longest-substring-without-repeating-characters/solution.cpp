class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int st=0,end=0;
        int maxlen=0;

        unordered_map<char,int>mp;

        while(end < s.size()){

            if(mp.find(s[end]) != mp.end()){
                st = max(st, mp[s[end]] + 1);
            }
            
mp[s[end]] = end;
 maxlen = max(maxlen, end - st + 1);

            end++;
        }
        return maxlen;
    }
};
