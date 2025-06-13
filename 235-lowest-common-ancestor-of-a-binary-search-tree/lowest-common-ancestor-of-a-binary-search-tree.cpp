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
    TreeNode* check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)return NULL;
        // if(root->val==p->val || root->val==q->val)return root;
        // else if((p->val>root->val && q->val<root->val) || (q->val>root->val && p->val<root->val))return root;
        if(p->val<root->val && q->val<root->val)return check(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)return check(root->right,p,q);
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return check(root,p,q);
    }
};