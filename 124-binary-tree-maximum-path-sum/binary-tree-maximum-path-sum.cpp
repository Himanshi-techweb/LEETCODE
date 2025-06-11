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
    int sum=INT_MIN;
    int check(TreeNode* root){
        if(root==NULL)return 0;
        int lh=check(root->left);
        if(lh<0)lh=0;
        int rh=check(root->right);
        if(rh<0)rh=0;
        sum=max(sum,root->val+lh+rh);
        return root->val +max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right)return root->val;
        check(root);
      return sum;  
    }
};