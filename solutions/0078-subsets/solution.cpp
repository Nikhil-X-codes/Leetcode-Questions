class Solution {
public:

void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index) {
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element and move forward
    solve(nums, ans, output, index + 1);

    // Include the current element and move forward
    output.push_back(nums[index]);
    solve(nums, ans, output, index + 1);

    // Backtrack: Remove the last element added
    output.pop_back();
}

    vector<vector<int>> subsets(vector<int>& nums) {

       int index=0;
       vector<vector<int>>ans;
       vector<int>output;
       solve(nums,ans,output,index);
      
      return ans;
    }
};
