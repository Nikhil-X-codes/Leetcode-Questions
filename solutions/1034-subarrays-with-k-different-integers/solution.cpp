class Solution {
public:

    int solve(vector<int>& nums, int k) {

        if (k < 0)
            return 0;
        int count = 0, l = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {

            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
