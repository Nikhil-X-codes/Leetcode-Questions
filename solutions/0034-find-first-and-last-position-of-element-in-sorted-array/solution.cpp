class Solution {
public:

    int first(vector<int>& nums, int target, int st, int end) {
        int ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1; // Move left to find the first occurrence
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int last(vector<int>& nums, int target, int st, int end) {
        int ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans = mid;
                st = mid + 1; // Move right to find the last occurrence
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1}; // Edge case: empty array

        int st = 0;
        int end = n - 1;

        int firstIndex = first(nums, target, st, end);
        int lastIndex = last(nums, target, st, end);

        return {firstIndex, lastIndex};
    }
};

