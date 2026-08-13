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
    long long maxsum=INT_MIN;
    long long solve(TreeNode* root){
        if(root==NULL)return INT_MIN;
        long long l=max(0LL,solve(root->left));
        long long r=max(0LL,solve(root->right));
        maxsum=max(maxsum,l+r+root->val);
        return root->val+max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};