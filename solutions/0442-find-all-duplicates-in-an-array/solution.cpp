class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> count(n + 1, 0); // Adjust count size to handle potential values from 1 to n
        vector<int> duplicates;

        for (int num : nums) {
            count[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] > 1) {
                duplicates.push_back(i);
            }
        }

        return duplicates;
    }
};

