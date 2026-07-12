/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& output,
               vector<int>& res) {

        if (root == NULL)
            return;

        res.push_back(root->val);
        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL) {

            if (targetSum == 0)
                output.push_back(res);
        }

        solve(root->left, targetSum, output, res);
        solve(root->right, targetSum, output, res);

        res.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> output;
        vector<int> res;

        solve(root, targetSum, output, res);

        return output;
    }
};
