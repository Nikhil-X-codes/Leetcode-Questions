class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

       int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int remainder = total_sum % k;
    if (remainder == 0) {
        return 0;
    } else {
        return remainder;
    }


    }
};
