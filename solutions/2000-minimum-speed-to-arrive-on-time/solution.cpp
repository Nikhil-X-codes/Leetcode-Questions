class Solution {
public:
    bool solve(vector<int>& dist, double hour, int mid) {

        int n=dist.size();

        double time=0;

        for(int i=0;i<n-1;i++){
time += ceil((double)dist[i] / mid);
        }

        time += (double)dist[n-1]/mid;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int l = 1, r = 1e7;
        int ans = -1;

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
