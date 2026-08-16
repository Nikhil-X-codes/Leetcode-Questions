class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int current = 0;
        int ans = 0;

        for (int floor : requests) {
            ans += abs(current - floor);
            current = floor;
        }

        return ans;
    }
};
