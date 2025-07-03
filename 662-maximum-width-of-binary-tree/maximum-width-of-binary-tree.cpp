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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,long long>> q;
       q.push({root,0LL});
       int width=0;
       while(!q.empty()){
        int size=q.size();
        int mini_length=q.front().second;
        int first_ix=0;int end_ix=0;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front().first;
            int length=q.front().second-mini_length;
            q.pop();
            if(i==0) first_ix=length;
            if(i==size-1) end_ix=length;
            if(node->left)q.push({node->left,(long long)2*length+1}); 
            if(node->right)q.push({node->right,(long long)2*length+2}); 
        }
        width=max(width,end_ix-first_ix+1);
       } 
       return width;
    }
};