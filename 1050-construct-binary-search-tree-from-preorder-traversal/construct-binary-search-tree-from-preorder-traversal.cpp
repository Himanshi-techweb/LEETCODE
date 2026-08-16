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
    TreeNode* solve(int &i,int s,int e,vector<int>&pre){
        if(s>e || i>=pre.size())return NULL;
        int rootval=pre[i];
        int index=st[rootval];
        i++;
        TreeNode* root=new TreeNode(rootval);
        root->left=solve(i,s,index-1,pre);
        root->right=solve(i,index+1,e,pre);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> in=preorder;
        sort(in.begin(),in.end());
        
        for(int i=0;i<in.size();i++){
            st[in[i]]=i;
        }
        int i=0;
        return solve(i,0,in.size(),preorder);

    }
};