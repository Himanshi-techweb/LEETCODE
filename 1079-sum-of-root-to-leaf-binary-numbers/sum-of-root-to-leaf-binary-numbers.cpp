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
    int sum=0;
    int check(vector<int> &arr){
        // reverse(arr.begin(),arr.end());
        int count=1;int x=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
           x=x+(2*count)*arr[i];
           count=count*2;
        }
        return x;
    }
    void solve(TreeNode* root,vector<int> &arr){
      if(root==NULL ){
         return ;
      }
       arr.push_back(root->val);
       if(root->left==NULL && root->right==NULL)sum+=check(arr);    
        
        if(root->left)
        solve(root->left,arr);
        if(root->right)
        solve(root->right,arr);
        arr.pop_back();  
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int>arr;
        solve(root,arr);
        return sum;
    }
};