class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        int swaps = 0;

        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a,int b) {
            int sum1 = digitSum(a);
            int sum2 = digitSum(b);

            if (sum1 != sum2) {
                return sum1 < sum2;
            }

            return a < b;
        });

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[sorted[i]] = i;
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {

            if (vis[i] || mp[nums[i]] == i)
                continue;

            int curr = i;
            int cycles = 0;

            while (!vis[curr]) {
                vis[curr] = true;
                curr = mp[nums[curr]];
                cycles++;
            }

            swaps += cycles-1;
        }

        return swaps;
    }
};
