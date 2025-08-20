/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q) return root;

        TreeNode* lefty=lowestCommonAncestor(root->left,p,q);
        TreeNode* righty=lowestCommonAncestor(root->right,p,q);

         if(lefty && righty) return root; 

         return lefty ? lefty : righty;   // ek null hai aur dusra non null hai

    }
};
