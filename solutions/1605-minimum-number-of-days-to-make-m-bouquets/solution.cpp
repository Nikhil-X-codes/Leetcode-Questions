class Solution {
public:

    bool solve(vector<int>& bloomDay, int m, int k, int mid) {

        int flowers = 0;
        int bouquet = 0;

        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {

            if (bloomDay[i] <= mid) {
                flowers++;

                if (flowers == k) {
                    bouquet++;
                    flowers = 0;
                }

            }

            else {
                flowers = 0;
            }

        }

        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        int n = bloomDay.size();
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solve(bloomDay, m, k, mid)) {
                ans = mid;
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
