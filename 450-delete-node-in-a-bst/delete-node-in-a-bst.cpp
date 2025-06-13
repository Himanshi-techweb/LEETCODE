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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
      //TreeNode* root=root ;
        if(root->val==key){
          if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
          }
          else if(root->left ==NULL || root->right==NULL){
            if(root->left!=NULL){
               TreeNode* change=root->left;
               delete root;
               return change; 
            }
            else{
                TreeNode* change=root->right;
               delete root;
               return change; 
            }
          }
          else{
            TreeNode* justright=root->right;
            while(justright->left){
                justright=justright->left;
            }
            root->val=justright->val;
            root->right=deleteNode(root->right,justright->val);
          }
        }
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else {
            root->left=deleteNode(root->left,key);
        } 
      return root;
    }
};