class Solution {
public:
    vector<vector<int>> res;

    // Function to find pairs in the sorted array that sum up to the target
    void sums(vector<int>& nums, int target, int i, int j) {
        while (i < j) {
            // If the sum of nums[i] and nums[j] is greater than the target, decrement j
            if (nums[i] + nums[j] > target) {
                j--;
            }
            // If the sum of nums[i] and nums[j] is less than the target, increment i
            else if (nums[i] + nums[j] < target) {
                i++;
            }
            // If the sum of nums[i] and nums[j] equals the target
            else {
                // Avoid duplicates
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                // Add the triplet to the result
                res.push_back({-target, nums[i], nums[j]});

                // Move to the next elements
                i++;
                j--;
            }
        }
    }

    // Function to find all unique triplets in the array which gives the sum of zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Define the first element of the triplet and the target for the pair sum
            int n1 = nums[i];
            int target = -n1;

            // Find pairs that sum up to the target
            sums(nums, target, i + 1, nums.size() - 1);
        }

        // Return the result
        return res;
    }
};

