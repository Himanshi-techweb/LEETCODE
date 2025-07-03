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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int,map<int,vector<int>>> check;//col and corroesponding node
      queue<pair<TreeNode*,pair<int,int>>> q;//node,row,col
      q.push({root,{0,0}});
      while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int row=it.second.first;
            int col=it.second.second;
            check[col][row].push_back(node->val);
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
      }
      vector<vector<int>> ans;
      for(auto [col,colmap]:check){
        vector<int> temp;
        for(auto [row,val]:colmap){
            sort(val.begin(),val.end());
            temp.insert(temp.end(),val.begin(),val.end());
        }
        ans.push_back(temp);
      }
      return ans;
    }
};