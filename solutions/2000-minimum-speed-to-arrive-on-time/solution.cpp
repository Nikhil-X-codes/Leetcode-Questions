class Solution {
public:
    bool solve(vector<int>& dist, double hour, int mid) {

        double time = 0.0;

        for (int i = 0; i < dist.size() - 1; i++) {

            time += ceil((double)dist[i] / mid);
        }

        time += (double)dist[dist.size() - 1] / mid;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        if(dist.size() > ceil(hour)) return -1;

        int ans = -1;
        int l = 1, r = 1e7;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (solve(dist, hour, mid)) {
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
