class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();

        vector<int> prefixGcd(n);

        int maxi = nums[0];

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        for (int i = 0; i < n / 2; i++) {
            sum += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return sum;
    }
};
