class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        long long prev = (int)lower - 1;

        for (int i : nums) {

            if (i < prev || i > upper)
                continue;

            if (i > prev+1) {
                ans.push_back({(int)prev + 1, i - 1});
            }

            prev = i;
        }

        if (prev < upper)
            ans.push_back({(int)prev + 1, upper});

        return ans;
    }
};
