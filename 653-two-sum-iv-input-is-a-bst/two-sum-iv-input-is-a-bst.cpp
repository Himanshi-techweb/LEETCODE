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
    unordered_set<int> check;bool here=false;
    void calc(TreeNode* root,int k){
        if(root==NULL)return;
        if(root->left){
            calc(root->left,k);
        }
        int i=root->val;
        int j=k-i;
        if(check.find(j)!=check.end()){
           here=true;
           return;
        }
        check.insert(i);
        if(root->right){
            calc(root->right,k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
       calc(root,k);
       if(here)return true;
       return false; 
    }
};