class Solution {
public:
    string findValidPair(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        // Count frequency of each digit
        for (char c : s) {
            mp[c]++;
        }

        string ans="";

        // Iterate through the string to find a valid adjacent pair
        for (int i = 0; i < n - 1; i++) {
            char first = s[i], second = s[i + 1];

            // Check if both digits satisfy the frequency condition and are different
            if (first != second && mp[first] == (first - '0') && mp[second] == (second - '0')) {
                ans += first;
                ans += second;
                return ans;
            }
        }

        return ans;  // No valid pair found
    }
};

