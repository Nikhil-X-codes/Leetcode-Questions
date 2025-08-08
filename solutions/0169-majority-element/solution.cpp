class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        
        // Phase 1: Find candidate using voting
        for(int i : nums) {
            if(count == 0) {
                candidate = i;
            }
            // Key logic you were missing:
            if(i == candidate) count++;
            else count--;
        }
        
        // Phase 2: Verify candidate
        count = 0; // Reset and count occurrences
        for(int j : nums) {
            if(j == candidate) count++; // Only count matches
        }
        
        return (count > nums.size()/2) ? candidate : -1;
    }
};
