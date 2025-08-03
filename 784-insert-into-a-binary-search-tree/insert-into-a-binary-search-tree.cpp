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
    TreeNode* solve(TreeNode* root,int val){
        if(root==NULL){
            TreeNode* new_node=new TreeNode(val);
            return new_node;
            // return NULL;
        }
        // if(root->left==NULL && root->right==NULL){
            
        // }
        // return;
        if(root->val>val){
            root->left= solve(root->left,val);
        }
        else {
            root->right=solve(root->right,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       return solve(root,val); 
    }
};