class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if (m > n) return false;

        unordered_map<char, int> mp, mp1;

        for (char c : s1) {
            mp[c]++;
        }

        int i = 0, j = 0;

        while (j < n) {
            mp1[s2[j]]++;

            if (j - i + 1 > m) {
                mp1[s2[i]]--;
                if (mp1[s2[i]] == 0) {
                    mp1.erase(s2[i]);
                }
                i++;
            }

            if (mp == mp1) return true;

            j++;
        }

        return false;
    }
};

