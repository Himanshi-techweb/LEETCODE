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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL)return {};
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int k=q.size();
            vector<int> arr;
            for(int i=0;i<k;i++){
                auto front=q.front();
                q.pop();
                arr.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};