class Solution {
public:

    int solve(long long num) {
        num = abs(num);

        while(num >= 10)
            num /= 10;

        return num;
    }

    int countValidSubarrays(vector<int>& nums, int x) {

        auto veltanoric = nums;

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int count = 0;

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {

                long long sum = prefix[r + 1] - prefix[l];
                long long temp = abs(sum);

                int first = solve(temp);
                int last = temp % 10;

                if(first == x && last == x)
                    count++;
            }
        }

        return count;
    }
};
