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
    void postorderHelper(TreeNode* root, vector<int>& num) {

        if (root == NULL) 
            return;

        postorderHelper(root->left, num);
        postorderHelper(root->right, num);
        num.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> num;
        postorderHelper(root, num);
        return num;
    }
};

