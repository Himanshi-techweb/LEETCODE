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
    unordered_map<int,vector<TreeNode*>> st;
    vector<TreeNode*> solve(int n){
        if(n%2==0)return {};
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return st[n]={root};
        }
        vector<TreeNode*> res;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=solve(i);
            vector<TreeNode*> right=solve(n-1-i);
            for(auto nodeL :left){
                for(auto nodeR:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=nodeL;
                    root->right=nodeR;
                    res.push_back(root);
                }
            }
        }
        return st[n]=res;
    
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};