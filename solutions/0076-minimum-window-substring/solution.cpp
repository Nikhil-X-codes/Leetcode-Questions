class Solution {
public:
    string minWindow(string s, string t) {
        
        int m = s.size();
        int n = t.size();

        if (n > m) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int countreq = n; // Total characters required
        int minwindowsize = INT_MAX;

        int start_i = 0; // Start index of the minimum window
        int i = 0, j = 0;

        while (j < m) {

            char ch = s[j];
            if (mp[ch] > 0) countreq--;
            mp[ch]--;

            // Shrink the window when all characters are matched
            while (countreq == 0) {

                int currwindowsize = j - i + 1;
                if (minwindowsize > currwindowsize) {
                    minwindowsize = currwindowsize;
                    start_i = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) countreq++;
                i++;
            }

            j++;
        }

        return minwindowsize == INT_MAX ? "" : s.substr(start_i, minwindowsize);
    }
};

