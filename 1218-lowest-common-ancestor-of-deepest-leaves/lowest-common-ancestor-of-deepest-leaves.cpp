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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
       map<TreeNode*,TreeNode*> check;
       check[root]=root;
       vector<TreeNode*> deepest;
       while(!q.empty()){
          int x=q.size();
          deepest.clear();
          for(int i=0;i<x;i++){
            TreeNode* node=q.front();
            q.pop();
            deepest.push_back(node);
            if(node->left){
                q.push(node->left);
                check[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                check[node->right]=node;
            }
          }
       }
       while(deepest.size()>1){
           unordered_set<TreeNode*> check_set;
          for(int i=0;i<deepest.size();i++){
            //deepest[i]=check[deepest[i]];
             check_set.insert(check[deepest[i]]);
          }
          deepest.assign(check_set.begin(),check_set.end());
          //deepest.erase(unique(deepest.begin(),deepest.end()),deepest.end());
       } 
       return deepest[0];
    }
};