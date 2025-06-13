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
        TreeNode* check(vector<int> & preorder,int ub,int &i){
        if(i>=preorder.size() || preorder[i]>ub)return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=check(preorder,root->val,i);
        root->right=check(preorder,ub,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return check(preorder,INT_MAX,i);
    }
};