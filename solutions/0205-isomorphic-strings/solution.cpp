class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;

        for (int i = 0; i < s.size(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            if (mp.find(c1) != mp.end()) {

                if (mp[c1] != c2)
                    return false;
            }
            else{
                mp[c1]=c2;
            }

            if (mp1.find(c2) != mp1.end()) {

                if (mp1[c2] != c1)
                    return false;
            }
             else
                mp1[c2] = c1;
        }

        return true;
    }
};
