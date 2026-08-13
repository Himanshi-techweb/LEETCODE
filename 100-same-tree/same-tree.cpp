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
    bool solve(TreeNode* x,TreeNode* y){
        if(x==NULL && y==NULL)return true;
        if((x==NULL && y!=NULL) || (y==NULL && x!=NULL) || x->val!=y->val)return false;
        
        bool l=solve(x->left,y->left);
        bool r=solve(x->right,y->right);
        bool ans=(l && r && x->val ==y->val);
        return ans;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};