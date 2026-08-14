class Solution {
public:
    int maximumLengthSubstring(string s) {

        int l = 0;
        int maxlen = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {

            mp[s[r]]++;

            while (mp[s[r]] > 2) {
                mp[s[l]]--;

                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }

                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
