class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> maxProd(n);
        vector<int> minProd(n);

        maxProd[0] = nums[0];
        minProd[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            maxProd[i] = max({nums[i], nums[i] * maxProd[i - 1],
                             nums[i] * minProd[i - 1]});

            minProd[i] = min({nums[i], nums[i] * maxProd[i - 1],
                             nums[i] * minProd[i - 1]});

            ans = max(ans, maxProd[i]);
        }

        return ans;
    }
};
