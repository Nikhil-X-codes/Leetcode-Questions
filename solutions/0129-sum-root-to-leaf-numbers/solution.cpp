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
    
    int solve(TreeNode* root,int currsum){
       
       if(root == NULL) return 0;

       currsum=currsum*10+root->val;

       if(root->left == NULL && root->right == NULL) return currsum;

       return solve(root->left,currsum) + solve(root->right,currsum);
    }

    int sumNumbers(TreeNode* root) {
        
        int res=solve(root,0);

        return res;
    }
};
