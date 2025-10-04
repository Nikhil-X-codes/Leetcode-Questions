
class Solution {
public:
    unordered_map<int, int> mp; 

    TreeNode* solve(int start, int end, vector<int>& preorder, vector<int>& inorder, int& index) {
        if (start > end) return nullptr;

        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->left = solve(start, pos - 1, preorder, inorder, index);
        root->right = solve(pos + 1, end, preorder, inorder, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int index = 0; 
        return solve(0, inorder.size() - 1, preorder, inorder, index);
    }
};

