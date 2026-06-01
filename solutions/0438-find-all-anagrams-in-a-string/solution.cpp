class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int window = p.size();
        int l=0;

        unordered_map<int, int> mp1, mp2;

        vector<int> res;

        for (char c : p) {
            mp2[c]++;
        }

        for (int r = 0; r < n; r++) {

            mp1[s[r]]++;

            if (r - l + 1 > p.size()) {
                mp1[s[l]]--;

                if (mp1[s[l]] == 0) {
                    mp1.erase(s[l]);
                }

                l++;
            }

            if (mp1 == mp2 && r - l + 1 == p.size())
                res.push_back(l);
        }

        return res;
    }
};
