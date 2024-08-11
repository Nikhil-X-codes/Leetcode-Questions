class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count the occurrences of each number in the array
        for (int num : arr) {
            mp[num]++;
        }

        unordered_set<int> occurrenceSet;

        // Check if the occurrences are unique
        for (const auto& pair : mp) {
            if (occurrenceSet.find(pair.second) != occurrenceSet.end()) {
                return false; // If occurrence count is already in the set, it's not unique
            }
            occurrenceSet.insert(pair.second);
        }

        return true; // All occurrences are unique
    }
};
