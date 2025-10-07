/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void mappings(TreeNode* node, TreeNode* parent) {

        if (node == nullptr)
            return;

        mp[node] = parent;

        mappings(node->left, node);   
        mappings(node->right, node); 
    }

    TreeNode* target(TreeNode* root, int start) {

        if (root == nullptr)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* lefty = target(root->left, start);
        if (lefty)
            return lefty;

        TreeNode* righty = target(root->right, start);
        if (righty)
            return righty;

        return nullptr;
    }

    int burn(TreeNode* root, int start) {

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        TreeNode* targetnode = target(root, start);

        q.push(targetnode);
        visited[targetnode] = true;

        int count = 0;

        while (!q.empty()) {

            int n = q.size();
            bool res = false;

            for (int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    res = true;
                }

                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    res = true;
                }

                if (mp[curr] != nullptr && !visited[mp[curr]]) {
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                    res = true;
                }
            }

            if (res)
                count++;
        }

        return count;
    }

    int amountOfTime(TreeNode* root, int start) {

        mappings(root, nullptr);
        int output = burn(root, start);

        return output;
    }
};
