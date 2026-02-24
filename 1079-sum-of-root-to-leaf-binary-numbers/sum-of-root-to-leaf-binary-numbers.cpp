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
    int sum=0;
    
    void solve(TreeNode* root,vector<int> &arr,int curr){
      if(root==NULL ){
         return ;
      }
       
       curr=curr*2 +root->val;
       if(root->left==NULL && root->right==NULL){
          sum+=curr;return;
       }    
        solve(root->left,arr,curr);
        solve(root->right,arr,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int>arr;
        solve(root,arr,0);
        return sum;
    }
};