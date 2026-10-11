
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 1;
        int len = 1;

        int rem = ((nums[0] % k) + k) % k;

        for (int i = 1; i < n; i++) {
            int curr = ((nums[i] % k) + k) % k;

            if (curr == rem) {
                len++;
            } else {
                len = 1;
                rem = curr;
            }

            if ((1LL * (len - 1) * rem) % k == 0) {
                ans = max(ans, len);
            }
        }

        return ans;
    }
};

