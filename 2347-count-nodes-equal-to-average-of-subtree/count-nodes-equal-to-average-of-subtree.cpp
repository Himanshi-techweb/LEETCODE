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
    int cnt=0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return {0,0};
        int root_val=root->val;
        auto l=solve(root->left);
        auto r=solve(root->right);
        int lsum=l.first;int lcnt=l.second;
        int rsum=r.first;int rcnt=r.second;
        if(((lsum+rsum+root_val)/(1+lcnt+rcnt))==root_val)cnt++;
        return {lsum+rsum+root_val,lcnt+rcnt+1};
    }
    int averageOfSubtree(TreeNode* root) {
         solve(root);
         return cnt;
    }
};