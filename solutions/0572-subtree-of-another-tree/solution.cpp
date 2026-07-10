class Solution {
public:

    bool issametree(TreeNode* root, TreeNode* subRoot) {
        
        if (root == NULL && subRoot == NULL)
            return true;

        if (root == NULL || subRoot == NULL)
            return false;

        if (root->val != subRoot->val)
            return false;

        return issametree(root->left, subRoot->left) &&
               issametree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (root == NULL)
            return false;

        if (issametree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
