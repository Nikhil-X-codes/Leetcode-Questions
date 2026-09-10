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

    int ans = 0;

    pair<int,int>dfs(TreeNode* root){
        
        if(root == NULL) return {0,0};

        auto lefty = dfs(root->left);
        auto righty = dfs(root->right);

        int sum = lefty.first+righty.first+root->val;
        int count = lefty.second+righty.second+1;

        if(sum/count == root->val) ans++;

        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
