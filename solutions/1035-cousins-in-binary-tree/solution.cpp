class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> mp; 
        
        while(!q.empty()){

            int size = q.size();
            bool foundX = false, foundY = false;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    mp[node->left->val] = node->val;
                    q.push(node->left);

                    if(node->left->val == x) foundX = true;
                    if(node->left->val == y) foundY = true;
                }

                if(node->right){
                    mp[node->right->val] = node->val;
                    q.push(node->right);

                    if(node->right->val == x) foundX = true;
                    if(node->right->val == y) foundY = true;
                }
            }

            if(foundX && foundY) {
                return mp[x] != mp[y];
            }

            if(foundX || foundY) return false;
        }

        return false;
    }
};
