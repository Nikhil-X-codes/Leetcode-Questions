class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
   std::unordered_map<int, int> numCounts;
    std::vector<int> duplicates;

    // Count each element
    for (int num : nums) {
        numCounts[num]++;
    }

    // Collect elements with count > 1
    for (const auto& entry : numCounts) {
        if (entry.second > 1) {
            duplicates.push_back(entry.first);
        }
    }

    return duplicates;
    }
};

