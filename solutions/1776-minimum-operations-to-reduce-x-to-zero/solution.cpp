class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int l = 0;
        int maxlen = -1;

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target < 0) return -1;

        if(target == 0) return n;

        int sum = 0;

        for (int r = 0; r < n; r++) {

            sum += nums[r];

            while (sum > target) {
                sum -= nums[l];
                l++;
            }

            if (sum == target) {
                maxlen = max(maxlen, r - l + 1);
            }

        }

        return maxlen == -1 ? -1 : n - maxlen;
    }
};
