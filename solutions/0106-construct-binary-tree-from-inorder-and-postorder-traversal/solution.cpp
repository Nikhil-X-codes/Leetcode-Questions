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
    
    unordered_map<int, int> mp; 

    TreeNode* solve(int start, int end,vector<int>& inorder, vector<int>& postorder, int& index) {
        if (start > end) return nullptr;

        int val = postorder[index--];
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->right = solve(pos + 1, end, inorder,postorder, index);

        root->left = solve(start, pos - 1, inorder,postorder,index);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int index = postorder.size()-1; 
        return solve(0, inorder.size() - 1, inorder , postorder, index);

    }
};
