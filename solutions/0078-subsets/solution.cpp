class Solution {
public:

    void solve(vector<int>& nums, int n, int index, vector<vector<int>>& output,
               vector<int>& res) {

            output.push_back(res);

        for (int i = index; i < n; i++) {
            res.push_back(nums[i]);
            solve(nums, n, i + 1,output,res);
            res.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> output;
        int n=nums.size();

        vector<int> res;

        solve(nums, n, 0, output, res);

        return output;
    }
};
