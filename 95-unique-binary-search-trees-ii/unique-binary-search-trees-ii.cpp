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
    vector<TreeNode*>  solve(int l,int r){
        if(l>r)return {NULL};
        if(l==r){
            TreeNode* newnode=new TreeNode(l);
            return {newnode} ;
        }
        vector<TreeNode*> res;
        for(int i=l;i<=r;i++){
            
            vector<TreeNode*> left=solve(l,i-1);
            vector<TreeNode*> right=solve(i+1,r);
            for(auto nodel:left){
                for(auto noder:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=nodel;
                    root->right=noder;
                    res.push_back(root);
                }

            }
        }
            return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};