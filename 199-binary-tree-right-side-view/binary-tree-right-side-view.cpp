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
     vector<int> ans;queue<int> q;
     void right(TreeNode* root,int level){
        if(root==NULL)return;
        if(q.size()==level){
            q.push(root->val);
        }
        right(root->right,level+1);
        right(root->left,level+1);
     }
    vector<int> rightSideView(TreeNode* root) {
       right(root,0);
       while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
       }return ans;
    }
};