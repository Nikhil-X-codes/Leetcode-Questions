

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long) m * k) {
            return -1; // Not enough flowers to make m bouquets
        }

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int bouquets = 0;
            int flowers = 0;

            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};



