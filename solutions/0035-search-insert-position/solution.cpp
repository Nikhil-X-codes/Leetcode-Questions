class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int st = 0;
        int end = n - 1;

 while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
              return mid;
              break;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
return st;
    }
};
