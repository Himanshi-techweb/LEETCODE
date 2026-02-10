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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    TreeNode* leftrotate(TreeNode* root){
        if(root==NULL || root->right==NULL)return root;
        TreeNode* B=root->right;
        TreeNode* C=B->left;
        B->left=root;
        root->right=C;
        return B;  
        
    }
    TreeNode* rightrotate(TreeNode* root){
        if(root==NULL || root->left==NULL)return root;
        TreeNode* B=root->left;
        TreeNode* C=B->right;
        B->right=root;
        root->left=C;
        return B;  
        
    }
    TreeNode* check(TreeNode* root){
        if(root==NULL)return root;
        root->left=check(root->left);
        root->right=check(root->right);
        int balance=height(root->left)-height(root->right);
        if(abs(balance)<=1)return root;
        //left
        if(balance>1){
            if(root->left){
                //ll
            if(height(root->left->left)>=height(root->left->right)){
                root=rightrotate(root);
            }
            //lr
            else{
                root->left=leftrotate(root->left);
                root=rightrotate(root);
            }
            }
            
        }
        else{
            if(root->right!=NULL){
               //rl
            if(height(root->right->left)>height(root->right->right)){
                root->right=rightrotate(root->right);
                root=leftrotate(root);
            }
            //rr
            else{
                root=leftrotate(root);
            }
            }
            
        }
        return check(root);
    }
    TreeNode* balanceBST(TreeNode* root) {
        return check(root);
    }
};