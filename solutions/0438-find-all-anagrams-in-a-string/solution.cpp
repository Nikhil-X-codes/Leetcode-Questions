class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        unordered_map<char, int> mp1, mp2;
        int l = 0;

        for (char c : p) {
            mp1[c]++;
        }

        int window = p.size();

        for (int r = 0; r < s.size(); r++) {

            mp2[s[r]]++;

            if (r - l + 1 > window) {

                mp2[s[l]]--;

                if (mp2[s[l]] == 0) {
                    mp2.erase(s[l]);
                }
                l++;
            }

            if (r - l + 1 == window && mp1 == mp2) {
                res.push_back(l);
            }
            
        }

        return res;
    }
};
