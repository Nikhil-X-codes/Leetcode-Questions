class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 2) return nums.size();  // If the array has 2 or fewer elements, no duplicates need to be removed

        int i = 2;  // Start from the third element
        
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] != nums[i-2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

