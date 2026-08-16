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
        if(root==NULL)return root;
        if(root->val>key){
            root->left=deleteNode(root->left,key); 
        }
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL) {
                TreeNode* another=root->right;
                delete root;
                return another;
            }
            else if(root->right==NULL){
                TreeNode* another=root->left;
                delete root;
                return another;

            }
            else{
                //take out maximum right then leftmost
                TreeNode* curr=root->right;
                while(curr->left!=NULL)curr=curr->left;
                
                root->val=curr->val;
                
                root->right=deleteNode(root->right,root->val);
                

            }

        }
        return root;

    }
};