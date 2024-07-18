class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;  // Create a map to store number and its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // Find the complement of the current number

            if (mp.find(complement) != mp.end()) {  // Check if the complement exists in the map
                return vector<int>{mp[complement], i};  // If found, return the indices
            }

            mp[nums[i]] = i;}  // Store the current number and its index in the map
return vector<int>{};    }
};


