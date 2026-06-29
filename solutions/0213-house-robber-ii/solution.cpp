class Solution {
public:
    int solve(int st, int end, vector<int>& nums) {

        // if (index > end)
        //     return 0;

        // int inc = nums[index] + solve(index + 2, end, nums);
        // int exc = solve(index + 1, end, nums);

        // return max(inc, exc);

        if (st == end)
            return nums[st];

        vector<int> dp(nums.size(), 0);

        dp[st] = nums[st];
        dp[st + 1] = max(nums[st], nums[st + 1]);

        for (int i = st + 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        // int case1 = solve(0, n - 2, nums);
        // int case2 = solve(1, n - 1, nums);

        // return max(case1, case2);

        return max(solve(0, n - 2,nums), solve(1, n - 1,nums));
    }
};
