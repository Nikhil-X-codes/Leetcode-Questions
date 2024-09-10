class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;

        int st=0,end=0;
        int maxlen=0;

        while(end < s.length()){
         
    if(mp.find(s[end]) != mp.end()){
       st = max(st, mp[s[end]] + 1);
    }
            
mp[s[end]] = end;

maxlen=max(maxlen,end-st+1);

      end++;
        }
return maxlen;
    }
};
