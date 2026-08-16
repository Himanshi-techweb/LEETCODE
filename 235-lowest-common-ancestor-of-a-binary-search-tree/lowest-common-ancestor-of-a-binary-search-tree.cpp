/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root,TreeNode* x,TreeNode* y){
        if(root==NULL || root==x || root==y)return root;
        if((x->val>root->val && y->val>root->val))return solve(root->right,x,y);
        else if(x->val<root->val && y->val<root->val)return solve(root->left,x,y);
        else return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};