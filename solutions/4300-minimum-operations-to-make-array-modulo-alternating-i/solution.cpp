class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        int ans = INT_MAX;

        for(int x = 0; x < k; x++) {

            for(int y = 0; y < k; y++) {

                if(x == y) continue;

                int count = 0;

                for(int m = 0; m < n; m++) {

                    int r = ((nums[m] % k) + k) % k;

                    int target = (m % 2 == 0) ? x : y;

                    int diff = abs(r - target);

                    count += min(diff, k - diff);
                }

                ans = min(ans, count);
            }
        }

        return ans;
    }
};
