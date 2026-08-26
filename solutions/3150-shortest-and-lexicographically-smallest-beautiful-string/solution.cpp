class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int l = 0;
        int minlen = INT_MAX;

        int n =s.size();

        int ones = 0;
        string ans = "";

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                ones++;

            while (ones == k) {

                int len = r - l + 1;

                if (len < minlen) {
                    minlen = len;
                    ans = s.substr(l, len);
                }

                else if (len == minlen) {
                    ans = min(ans, s.substr(l, minlen));
                }

                if (s[l] == '1')
                    ones--;

                l++;
            }
        }

        return ans;
    }
};
