class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        long long MOD = 1e9 + 7;
        map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int b = 0;

            while (nums[i] > 0) {

                if (nums[i] % 2 == 1) {
                    mp[b]++;
                }

                nums[i] /= 2;
                b++;
            }
            
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {

            long long x = 0;
            long long place = 1;

            for (int b = 0; b < 31; b++) {

                if (mp[b] > 0) {
                    mp[b]--;
                    x += place;
                }

                place *= 2;
            }

            ans = (ans + (x * x) % MOD) % MOD;
        }

        return (int)ans;
    }
};
