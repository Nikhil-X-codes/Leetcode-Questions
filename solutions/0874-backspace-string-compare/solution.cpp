class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string s1, s2;

        for (char c : s) {
            if (c != '#') {
                s1 += c;
            } else if (!s1.empty()) {
                s1.pop_back();
            }
        }

        for (char c : t) {
            if (c != '#') {
                s2 += c;
            } else if (!s2.empty()) {
                s2.pop_back();
            }
        }

        return s1 == s2;
    }
};

