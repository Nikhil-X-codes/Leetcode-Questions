class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxfreq = 0;
        int left = 0;
        int maxlen = 0;

        unordered_map<char,int>mp;

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;
            maxfreq = max(maxfreq, mp[s[i]]);

        while ((i - left + 1) - maxfreq > k) {
                mp[s[left]]--;

                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }

                left++;
            }

            maxlen = max(maxlen, i - left + 1);
        }

        return maxlen;
    }
};
