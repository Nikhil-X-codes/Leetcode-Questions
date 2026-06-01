class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxfreq = 0;
        int st = 0;
        int end = 0;
        int maxlen = 0;

        unordered_map<char, int> mp;

        while (end < s.size()) {
            mp[s[end]]++;

            maxfreq = max(maxfreq, mp[s[end]]);

            if ((end - st + 1) - maxfreq > k) {
                mp[s[st]]--;

                if (mp[s[st]] == 0) {
                    mp.erase(s[st]);
                }

                st++;
            }

            maxlen = max(maxlen,end-st+1);
            end++;
        }

        return maxlen;
    }
};
