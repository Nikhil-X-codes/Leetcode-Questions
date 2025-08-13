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

    int height(TreeNode* root){
       
       if(root == NULL) return -1;

       int lefty=height(root->left);
       int righty=height(root->right);

       return  max(lefty,righty) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL) return true;

        int ans= abs(height(root->left) - height(root->right) );

        if(ans > 1) return false;
        
       return isBalanced(root->left) && isBalanced(root -> right);
    }
};
