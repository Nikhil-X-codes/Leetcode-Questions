class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int n = nums.size();
        int i = 0, j = n - 1;

        int count = 0;

        while (i < j) {

            if (nums[i] != 0) {
                i++;
                continue;
            }
            
            if (nums[j] == 0) {
                j--;
                continue;
            }

            swap(nums[i], nums[j]);
            count++;
            i++;
            j--;
        }

        return count;
    }
};
