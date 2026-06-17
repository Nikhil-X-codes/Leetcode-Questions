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
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,int st, int end) {

        if (st > end)
            return nullptr;

        int val = preorder[index++];

        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->left = solve(preorder, inorder, index, st, pos - 1);
        root->right = solve(preorder, inorder, index, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int index = 0;

        return solve(preorder, inorder, index, 0, n-1);
    }
};
