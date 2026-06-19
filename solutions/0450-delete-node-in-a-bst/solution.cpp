class Solution {
public:
    TreeNode* succ(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else { // node found

            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* successor = succ(root->right);

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};
