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
        // if(root->left==NULL && root->right==NULL)return root->val;
        int lsum=max(0,check(root->left));
        int rsum=max(0,check(root->right));
        sum=max(sum,lsum+root->val+rsum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        check(root);
        return sum;
    }
};