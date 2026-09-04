class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
         int n = nums.size();

        vector<int> leftmax(n);
        leftmax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], nums[i]);
        }

        vector<int> rightmin(n);
        rightmin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightmin[i] = min(rightmin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {

            if (leftmax[i] - rightmin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
