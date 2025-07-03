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
    TreeNode* check(vector<int> &pre,int &i,int ub){
        if(i>pre.size()-1 || pre[i]>ub)return NULL;
        TreeNode* node=new TreeNode(pre[i++]);
        node->left=check(pre,i,node->val);
        node->right=check(pre,i,ub);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return check(preorder,i,INT_MAX);
    }
};