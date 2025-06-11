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
     map<int,map<int,multiset<int>> > check;// vertical ,level ,node
     queue<pair<TreeNode*,pair<int,int>>> q;//node,vertical,level
     vector<vector<int>> ans;
     q.push({root,{0,0}});
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size ;i++){
            auto w=q.front();
            q.pop();
            TreeNode* node=w.first;
            int c=w.second.first;
            int h=w.second.second;
            check[c][h].insert(node->val);
            if(node->left){
                q.push({node->left,{c-1,h+1}});
            }
            if(node->right){
                q.push({node->right,{c+1,h+1}});
            }
        }
     }
     for(auto i:check){
       vector<int> arr;
       for(auto j: i.second){
         arr.insert(arr.end(),j.second.begin(),j.second.end());
       }
       ans.push_back(arr);
     }
     return ans;   
    }
};