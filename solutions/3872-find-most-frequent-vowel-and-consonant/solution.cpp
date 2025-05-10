class Solution {
public:
    int maxFreqSum(string s) {

        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> vowelCounts;
    unordered_map<char, int> consonantCounts;
    
    for (char c : s) {
        if (vowels.find(c) != vowels.end()) {
            vowelCounts[c]++;
        } else {
            consonantCounts[c]++;
        }
    }
    
    int maxVowel = 0;
    for (const auto &pair : vowelCounts) {
        if (pair.second > maxVowel) {
            maxVowel = pair.second;
        }
    }
    
    int maxConsonant = 0;
    for (const auto &pair : consonantCounts) {
        if (pair.second > maxConsonant) {
            maxConsonant = pair.second;
        }
    }
    
    return maxVowel + maxConsonant;
        
    }
};
