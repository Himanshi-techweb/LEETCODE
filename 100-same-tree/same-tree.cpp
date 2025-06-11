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
    bool check(TreeNode* i,TreeNode* j){
        if((i==NULL && j!=NULL)|| (i!=NULL  && j==NULL))return false;
        if(i==NULL && j==NULL)return true;
        if(i!=NULL && j!=NULL && i->val!=j->val)return false;
        return check(i->left,j->left)&&check(i->right,j->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return  check(p,q);
    }
};