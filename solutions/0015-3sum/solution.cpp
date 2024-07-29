class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // Sort the array to use two pointers technique
        sort(nums.begin(), nums.end());

        // Traverse the array
        for (int i = 0; i < nums.size(); ++i) {
            // Avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    --k; // Decrease k to reduce the sum
                } else if (sum < 0) {
                    ++j; // Increase j to increase the sum
                } else {
                    // Found a triplet
                    res.push_back({nums[i], nums[j], nums[k]});
                    // Avoid duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    ++j;
                    --k;
                }
            }
        }

        return res;
    }
};

