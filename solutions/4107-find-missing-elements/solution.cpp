class Solution {
public:
    bool isfound(int num, vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            if (num == nums[i])
                return true;
        }

        return false;
    }

    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> res;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        for (int i = mini; i <= maxi; i++) {
            if (!isfound(i, nums)) {
                res.push_back(i);
            }
        }

        return res;
    }
};
