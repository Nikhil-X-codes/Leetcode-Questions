class Solution {
public:
    vector<int> lpsarray(string needle) {
        int m = needle.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // ✅ correct way
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps = lpsarray(needle);

        int i = 0, j = 0; // i -> haystack, j -> needle
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }

            if (j == needle.size()) {
                return i - j; // match found
            } else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // use prefix info
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};

