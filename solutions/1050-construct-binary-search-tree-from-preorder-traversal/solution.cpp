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
    
    TreeNode* insertBST(vector<int>& preorder,int &i, int mini,int maxi) {
       
       if(i >= preorder.size() || preorder[i] < mini || preorder[i] > maxi) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = insertBST(preorder, i, mini, root->val);
        root->right = insertBST(preorder, i, root->val, maxi);
        
       return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int i=0;
      TreeNode*res=insertBST(preorder,i,INT_MIN,INT_MAX);
      return res;
    }
};
