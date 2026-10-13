class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long even = 0;
        long long odd = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long neweven = max(even, odd - nums[i]);
            long long newodd = max(odd, even + nums[i]);

            even = neweven;
            odd = newodd;
        }

        return max(even, odd);
    }
};
