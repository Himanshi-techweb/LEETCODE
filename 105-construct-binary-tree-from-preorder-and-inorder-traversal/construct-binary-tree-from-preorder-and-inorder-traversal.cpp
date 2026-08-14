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
    unordered_map<int,int> st;
    TreeNode* solve(int &i,int s,int e,vector<int> &pre,vector<int>&in){
        
        if(s>e)return NULL;
        if(i>=pre.size())return NULL;
        int getindex=st[pre[i]];
        TreeNode* root=new TreeNode(pre[i++]);
        root->left=solve(i,s,getindex-1,pre,in);
        root->right=solve(i,getindex+1,e,pre,in);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        for(int i=0;i<in.size();i++){
            st[in[i]]=i;
        }
        int i=0;
        return solve(i,0,pre.size()-1,pre,in);
    }
};