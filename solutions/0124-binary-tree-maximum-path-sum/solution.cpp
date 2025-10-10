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
     
    int maxsum=INT_MIN;

    int sum(TreeNode* root){
      
      if(root == nullptr) return 0;
      
      int leftgain=max(sum(root->left),0);
      int rightgain=max(sum(root->right),0);

      int currsum=root->val+leftgain+rightgain;

      maxsum=max(maxsum,currsum);

      return root->val+max(leftgain,rightgain);
    }

    int maxPathSum(TreeNode* root) {
        
        sum(root);
        return maxsum;
    }
};
