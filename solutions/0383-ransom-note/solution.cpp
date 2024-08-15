
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;

        for (char c : magazine) {
            charCount[c]++;
        }

        for (char c : ransomNote) {
            if (charCount[c] > 0) {
                charCount[c]--;
            } else {
                return false; 
            }
        }
        
        return true;
    }
};
