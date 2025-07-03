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
    bool check(TreeNode* root,long long mini,long long maxi){
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        if(!check(root->left,mini,root->val) || !check(root->right,root->val,maxi))return false;
        if(root->left && (root->left->val <=mini || root->left->val>=root->val))return false;
        if(root->right && (root->right->val >=maxi || root->right->val<=root->val))return false;
        return true;

    }
    bool isValidBST(TreeNode* root) {
       return check(root,-1e12,1e12);
    }
};