class Codec {
public:

    void dfs(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";

        dfs(root->left, s);
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    TreeNode* buildTree(stringstream &ss) {
        string val;
        ss >> val;

        if (val == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};
