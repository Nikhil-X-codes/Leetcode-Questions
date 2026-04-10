class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void parent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        mp[root] = NULL; 

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        parent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) break;

            dist++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (mp[node] && !visited.count(mp[node])) {
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};
