class Solution {
public:
    bool solve(vector<int>& nums, int k, int currsum, int target, int index,
               int n, vector<bool>& visited) {

        if (k == 1)
            return true;

        if (currsum == target) {
            return solve(nums, k - 1, 0, target, 0, n, visited);
        }

        for (int i = index; i < n; i++) {

            if (!visited[i] && currsum + nums[i] <= target) {

                visited[i] = true;

                if (solve(nums, k, currsum + nums[i], target, i + 1, n,
                          visited))
                    return true;

                visited[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        if (totalsum % k != 0)
            return false;

        int target = totalsum / k;

        vector<bool> visited(n, false);

        return solve(nums, k, 0, target, 0, n, visited);
    }
};
