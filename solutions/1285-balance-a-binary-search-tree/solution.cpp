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
     
    TreeNode* build(int l,int r,vector<int>&res){
         
        if(l > r) return NULL;

        int n=res.size();

        int mid=l+(r-l)/2;

        TreeNode* curr=new TreeNode(res[mid]);

        curr->left=build(l,mid-1,res);

        curr->right=build(mid+1,r,res);

        return curr;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>res;
        inorder(root,res);

        return build(0,res.size()-1,res);
    }
};
