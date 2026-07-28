class Solution {
public:
    string smallestPalindrome(string s) {

        map<char, int> mp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        string left = "";
        string middle = "";

        for (char c = 'a'; c <= 'z'; c++) {

            left += string(mp[c] / 2, c);
            if (mp[c] % 2 == 1)
                middle += c;
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};
