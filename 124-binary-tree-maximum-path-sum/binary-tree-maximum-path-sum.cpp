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
        if(root==NULL)return 0;
        long long leftsum=max(0LL,solve(root->left));
        long long rightsum=max(0LL,solve(root->right));
        // if(leftsum==INT_MIN  && rightsum==INT_MIN)return root->val;
        
        maxsum=max({maxsum,leftsum+rightsum+root->val,(long long)(root->val)});
        return root->val+max(leftsum,rightsum); 
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};