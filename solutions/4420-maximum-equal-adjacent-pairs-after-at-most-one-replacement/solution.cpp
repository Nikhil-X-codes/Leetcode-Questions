class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

       map < pair<int, int>, int > mp;
       int n = nums.size();

        int intial = 0;

        for (int i = 0; i + 1 < n; i++) {

            int a = nums[i];
            int b = nums[i + 1];

            if (a == b) {
                intial++;
            } else {
                mp[{a, b}]++;
                mp[{b, a}]++;
            }
        }

        int best = 0;

        for (auto [p, c] : mp) {
            best = max(best, c);
        }

        return intial + best;
    }
};
