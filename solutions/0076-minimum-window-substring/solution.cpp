#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) return "";

        unordered_map<char, int> target;
        for (char c : t) target[c]++;

        unordered_map<char, int> window;
        int l = 0, start = 0, minlen = INT_MAX;
        int formed = 0;
        int required = target.size(); 

        for (int r = 0; r < m; r++) {
            char c = s[r];
            window[c]++;

            if (target.count(c) && window[c] == target[c])
                formed++;

            while (l <= r && formed == required) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (target.count(leftChar) && window[leftChar] < target[leftChar])
                    formed--;

                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};

