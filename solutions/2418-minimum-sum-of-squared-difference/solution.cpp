
class Solution {
public:
    bool solve(vector<int>& diff, long long mid, long long k) {
        long long op = 0;

        for (int i : diff) {
            if (i > mid)
                op += i - mid;

            if (op > k)
                return false;
        }

        return true;
    }

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long total = 0;
        int maxdiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxdiff = max(maxdiff, diff[i]);
        }

        if (total <= k)
            return 0;

        long long low = 0, high = maxdiff;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (solve(diff, mid, k))
                high = mid-1;
            else
                low = mid + 1;
        }

        long long x = low;
        long long used = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long reduced = min((long long)diff[i], x);
            used += diff[i] - reduced;
            ans += reduced * reduced;
        }

        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= x && x > 0) {
                ans -= x * x - (x - 1) * (x - 1);
                remaining--;
            }
        }

        return ans;
    }
};

