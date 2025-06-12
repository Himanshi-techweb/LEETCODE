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
    vector<string> ans;
    void check(TreeNode* root,string x){
        if(root==NULL){
            return;
        }
        if(!x.empty())x+="->";
        x+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(x);
            return;
        }
        check(root->left,x);
        //x.pop_back();
        check(root->right,x);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
      string x="";
      check(root,x);
      return ans;

    }
};