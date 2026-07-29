class Solution {
public:
    int countways(vector<int>& nums, int element) {

        int count = 0;
        int len = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] <= element)
                len++;
            else
                len = 0;

            count += len;
        }

        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        return countways(nums, right) - countways(nums, left-1);
    }
};
