class Solution {
public:
int lengthOfLongestSubstring(string s) {
        
 int start = 0, end = 0; // Initialize both pointers
        unordered_set<char> st; // Set to store unique characters in the current window
        int maxlen = 0;

        for (end = 0; end < s.length(); end++) {
            // If character is already in the set, move start pointer to maintain uniqueness
            while (st.find(s[end]) != st.end()) {
                st.erase(s[start]);
                start++;
            }
            
            // Insert the current character into the set
            st.insert(s[end]);
            
            // Calculate max length of substring without repeating characters
            maxlen = max(maxlen, end - start + 1);
        }

        return maxlen;
    }

};
