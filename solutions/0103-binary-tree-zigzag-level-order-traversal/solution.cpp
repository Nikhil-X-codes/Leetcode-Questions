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

    void solve(TreeNode* root,vector<vector<int>>&output){
      
      if(root == NULL) return;

      queue<TreeNode*>q;

        q.push(root);
        bool leftToRight=true;

      while(!q.empty()){
        
      int n = q.size(); 
      vector<int>res(n);

      for(int i=0;i<n;i++){

                TreeNode* temp = q.front();
                q.pop();
             
               int index = leftToRight ? i : (n - 1 - i);
               res[index] = temp->val;

                if(temp->left != nullptr) {
                    q.push(temp->left);
                }

                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
      }

        leftToRight = !leftToRight;
        output.push_back(res);
      }


    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>output;
        solve(root,output);
        return output;
    }
};
