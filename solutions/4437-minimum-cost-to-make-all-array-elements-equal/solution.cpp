class Solution {
public:
    long long minCost(vector<int>& nums) {

        long long ans = LLONG_MAX;
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int j = i;

            while (j + 1 < n && nums[j + 1] == nums[i]) {
                j++;
            }

            int len = j - i + 1;

            if (j > 0 && i < n - 1) {
                long long cost = 1LL * (n - len) * nums[i];
                ans = min(ans, cost);
            }

            i = j + 1;
        }

        return ans;
    }
};
