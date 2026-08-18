class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> freq;
        unordered_map<int, int> count;

        int l = 0;

        for (int r = 0; r < n; r++) {

            freq[nums[r]]++;

            if (r - l + 1 == k) {

                for (auto& [x, f] : freq) {
                    count[x]++;
                }

                freq[nums[l]]--;

                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }

                l++;
            }
        }

        int ans = -1;

        for (auto& [x, c] : count) {
            if (c == 1) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};
