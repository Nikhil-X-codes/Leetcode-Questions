#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        // Count the frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        bool hasOdd = false, hasEven = false;

        // Find minEven and maxOdd frequencies
        for (auto& i : mp) {
            int count = i.second;

            if (count % 2 == 0) {
                minEven = min(minEven, count);
                hasEven = true;
            } else {
                maxOdd = max(maxOdd, count);
                hasOdd = true;
            }
        }

        // Check after loop to ensure both odd and even exist
        if (!hasOdd || !hasEven) {
            return -1;
        }

        return maxOdd - minEven;
    }
};

