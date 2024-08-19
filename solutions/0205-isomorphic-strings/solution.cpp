class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); ++i) {
            char ch1 = s[i];
            char ch2 = t[i];

            // Check if ch1 is already mapped to a different character
            if (mp1.find(ch1) != mp1.end()) {
                if (mp1[ch1] != ch2) {
                    return false;
                }
            } else {
                mp1[ch1] = ch2;
            }

            // Check if ch2 is already mapped to a different character
            if (mp2.find(ch2) != mp2.end()) {
                if (mp2[ch2] != ch1) {
                    return false;
                }
            } else {
                mp2[ch2] = ch1;
            }
        }

        return true;
    }
};

