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
    vector<TreeNode*> solve(int s,int e,int n){
       vector<TreeNode*> result;
       if(s>n || e<1)return {NULL};
       if(s>e)return {NULL};
       if(s==e){
        TreeNode* root=new TreeNode(s);
        return {root};
       }
       for(int i=s;i<=e;i++){
        vector<TreeNode*>  lefttree=solve(s,i-1,n);
        vector<TreeNode*>  righttree=solve(i+1,e,n);
        for(auto left:lefttree){
            for(auto right:righttree){
                TreeNode* root=new TreeNode(i);
                root->left=left;
                root->right=right;
                result.push_back(root);
            }
        }
       }
       return result;
    }
    vector<TreeNode*> generateTrees(int n) {
      return solve(1,n,n); 
    }
};