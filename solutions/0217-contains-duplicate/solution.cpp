class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     unordered_set<int> us;

        for (int num : nums) {
            if (!us.insert(num).second) {
                return true; // Found a duplicate
            }
        }
        return false; // No duplicates found
    }
};
