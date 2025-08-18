class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> output;
        map<int, map<int, vector<int>>> mp; 
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd][lvl].push_back(node->val);

            if (node->left) q.push({node->left, {hd - 1, lvl + 1}});
            if (node->right) q.push({node->right, {hd + 1, lvl + 1}});
        }

        for (auto& hdPair : mp) {
            vector<int> col;
            for (auto& lvlPair : hdPair.second) {
                auto vals = lvlPair.second;
                sort(vals.begin(), vals.end()); 
                col.insert(col.end(), vals.begin(), vals.end());
            }
            output.push_back(col);
        }

        return output;
    }
};

