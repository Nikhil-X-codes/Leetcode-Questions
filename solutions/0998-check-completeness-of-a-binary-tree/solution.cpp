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
    
    int count(TreeNode* root){
      if(root == nullptr) return 0;
      return count(root->left)+count(root->right)+1;
    }
    
    bool solve(TreeNode* root,int index,int nodecount){

                if(root == nullptr) return true;

        if(index >= nodecount) return false;

        bool lefty=solve(root->left,2*index+1,nodecount);
        bool righty=solve(root->right,2*index+2,nodecount);

        return lefty && righty;
    }

    bool isCompleteTree(TreeNode* root) {
        int nodecount=count(root);
        return solve(root,0,nodecount);
    }
};
