#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> arr;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        if (pattern.size() != arr.size()) return false;

        unordered_map<char, string> mp;    
        unordered_map<string, char> mp1;   

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = arr[i];

            if (mp.find(c) != mp.end()) {
                if (mp[c] != w) return false; 
            } else {
                mp[c] = w;
            }

            if (mp1.find(w) != mp1.end()) {
                if (mp1[w] != c) return false; 
            } else {
                mp1[w] = c;
            }
        }

        return true;
    }
};

