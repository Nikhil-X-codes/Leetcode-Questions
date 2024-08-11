#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> result;

        // Populate the hashmap with elements from nums1 and their frequencies
        for (int num : nums1) {
            map[num]++;
        }

        // Iterate over nums2 and check if elements exist in the hashmap
        for (int num : nums2) {
            // If the element exists and has a non-zero frequency
            if (map[num] > 0) {
                result.push_back(num);
                map[num]--; // Decrement the frequency to account for the match
            }
        }
 
        return result;
    }
};

