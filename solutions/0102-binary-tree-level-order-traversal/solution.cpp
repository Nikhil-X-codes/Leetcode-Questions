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
    void solve(TreeNode* root, vector<vector<int>>& output) {

        if(root == nullptr) {
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int levelSize = q.size(); 
            vector<int> currentLevel;
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                currentLevel.push_back(temp->val);

                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            output.push_back(currentLevel);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        solve(root, output);
        return output;
    }
};
