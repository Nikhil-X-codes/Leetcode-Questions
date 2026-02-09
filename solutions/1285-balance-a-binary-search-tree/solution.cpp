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

    void inorder(TreeNode* root,vector<int>&res){
       
       if(root == NULL) return;
       
       inorder(root->left,res);

       res.push_back(root->val);

       inorder(root->right,res);
    }

    TreeNode* build(TreeNode* root,vector<int>&res,int l,int e){

        if(l > e) return NULL;
        
        int mid = e+(l-e)/2;

         TreeNode* curr = new TreeNode(res[mid]);

         curr->left=build(root,res,l,mid-1);

         curr->right=build(root,res,mid+1,e);

         return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>res;
        inorder(root,res);

        return build(root,res,0,res.size()-1);
    }
};
