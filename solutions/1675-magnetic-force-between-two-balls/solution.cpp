class Solution {
public:
    bool isans(vector<int>& position, int m, int mid) {
        int n = position.size();
        int count = 1; // Place the first ball at the first position
        int prev = position[0];

        for (int i = 1; i < n; i++) {
            if (position[i] - prev >= mid) {
                count++;
                prev = position[i];
            }
            if (count == m) return true; // Successfully placed m balls
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int st = 0;
        int end = position[n - 1] - position[0];
        int result = 0;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isans(position, m, mid)) {
                result = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return result;
    }
};

