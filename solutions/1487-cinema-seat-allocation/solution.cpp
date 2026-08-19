class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> mp;

        for (auto &x : reservedSeats) {
            mp[x[0]].insert(x[1]);
        }

        int ans = 2 * (n - mp.size());

        for (auto &[row, reserve] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int i = 2; i <= 5; i++) {

                if (reserve.count(i)) {
                    left = false;
                    break;
                }
            }

            for (int i = 4; i <= 7; i++) {

                if (reserve.count(i)) {
                    middle = false;
                    break;
                }
            }

            for (int i = 6; i <= 9; i++) {

                if (reserve.count(i)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;

            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};
