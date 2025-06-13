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
    // vector<int> in;
    int count=0;
    int x=-1;
    void inorder(TreeNode* root,int k){
        if(root==NULL || count>=k)return;
        inorder(root->left,k);
        count++;
        if(count==k){
           x=root->val;
           return;
        }
        //in.push_back(root->val);
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
      inorder(root,k);
      return x;
    }
};