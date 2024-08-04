class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        
        // Generate all subarray sums
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                sub.push_back(sum);
            }
        }
        
        // Sort the subarray sums
        sort(sub.begin(), sub.end());
        
        // Calculate the range sum
        int ans = 0;
        int modulo = 1e9 + 7;  // Correct modulo value
        
        for (int i = left; i <= right; i++) {
            ans = (ans + sub[i - 1]) % modulo;
        }
        
        return ans;  // Return the correct result
    }
};

