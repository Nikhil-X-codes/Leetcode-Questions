class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        vector<int> result(n);
        int index = 0;

        for (int num : nums) {
            if (num < pivot) result[index++] = num;
        }

        for (int num : nums) {
            if (num == pivot) result[index++] = num;
        }

        for (int num : nums) {
            if (num > pivot) result[index++] = num;
        }

        return result;
    }
};

