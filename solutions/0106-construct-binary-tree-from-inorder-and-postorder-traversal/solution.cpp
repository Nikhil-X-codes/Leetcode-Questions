class Solution {
public:
    int index;

    int position(vector<int>& inorder, int st, int end, int key) {

        for (int i = st; i <= end; i++) {
            if (inorder[i] == key)
                return i;
        }

        return -1;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int left,
                    int right) {

        if (left > right)
            return NULL;

        int element = postorder[index--];

        TreeNode* root = new TreeNode(element);

        int pos = position(inorder, left, right, element);

        root->right = solve(inorder, postorder, pos + 1, right);
        root->left = solve(inorder, postorder, left, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        index = postorder.size() - 1;

        return solve(inorder, postorder, 0, inorder.size() - 1);
    }
};
