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
            int size = q.size();
            vector<int> curr;
            
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                curr.push_back(temp->val);
                
                // FIXED: Use temp instead of root
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            
            output.push_back(curr);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        solve(root, output);
        
        reverse(output.begin(), output.end());
        return output;
    }
};
