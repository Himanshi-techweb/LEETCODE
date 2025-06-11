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
    int maxi(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 0;
        int leftlength=maxi(root->left);
        int rightlength=maxi(root->right);
        return 1+max(leftlength,rightlength);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
       return 1+maxi(root); 
    }
};