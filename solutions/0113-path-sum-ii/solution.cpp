/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int targetSum,vector<vector<int>>&res,vector<int>&ans){
        
        if(root == NULL) return;

        ans.push_back(root->val);

        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            res.push_back(ans);
        }
       
       solve(root->left,targetSum-root->val,res,ans);
       solve(root->right,targetSum-root->val,res,ans);

        ans.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int>ans;
        
        solve(root,targetSum,res,ans);

        return res;
    }
};
