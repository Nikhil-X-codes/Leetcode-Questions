#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        int n = nums.size();
        long long total_pairs = (long long)n * (n - 1) / 2; 

        std::unordered_map<int, int> mp; 
        long long good_pairs = 0; 

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i; 
            good_pairs += mp[key]; 
            mp[key]++; 
        }

        return total_pairs - good_pairs;  
    }
};

