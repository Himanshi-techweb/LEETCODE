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
    TreeNode* solve(TreeNode* root, int key){
        if(root==NULL)return NULL;
        if(root->val==key){//node there
          if(root->left==NULL && root->right==NULL){
             delete root;
             return NULL;
          }
          else if(root->left==NULL || root->right==NULL){
            //left child exist;
            if(root->left){
                TreeNode* temp=root->left;
                while(temp->right)temp=temp->right;
                int x=temp->val;
                temp->val=root->val;root->val=x;
                root->left= solve(root->left,key);
            }
            else if(root->right){
                TreeNode* temp=root->right;
                while(temp->left)temp=temp->left;
                int x=temp->val;
                temp->val=root->val;root->val=x;
                root->right= solve(root->right,key);
            }
          }
          else{
            TreeNode* temp=root->left;
            while(temp->right)temp=temp->right;
            int x=temp->val;
            temp->val=root->val;root->val=x;
            root->left= solve(root->left,key);
          }
        }
        else if(root->val<key) root->right= deleteNode(root->right,key);
        else root->left= deleteNode(root->left,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val!=key){
          TreeNode* store=root;
          solve(root,key);
          return store;
        }
        else return solve(root,key);

    }
};