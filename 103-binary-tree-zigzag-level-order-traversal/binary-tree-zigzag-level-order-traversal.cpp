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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        bool righttoleft=false;
        while(!q.empty()){
            int size=q.size();
            vector<int> check;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                check.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            if(righttoleft){
                reverse(check.begin(),check.end());
                ans.push_back(check);
            }
            else{
                ans.push_back(check);
            }
            righttoleft=!righttoleft;
        }return ans;
    }
    
};