class Solution {
public:
    void solve(vector<TreeNode*>& res, TreeNode* root) {

        if (root == NULL)
            return;

        res.push_back(root);

        solve(res, root->left);
        solve(res, root->right);
    }

    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        vector<TreeNode*> res;

        solve(res, root);

        int n = res.size();

        for (int i = 0; i < n - 1; i++) {
            res[i]->left = NULL;
            res[i]->right = res[i + 1];
        }

        res[n - 1]->left = NULL;
        res[n - 1]->right = NULL;
    }
};
