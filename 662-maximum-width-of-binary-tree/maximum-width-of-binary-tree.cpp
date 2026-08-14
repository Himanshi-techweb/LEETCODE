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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL)return 1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0LL});
        long long first=0;
        long long sec=0;
        long long ans=0;int mini=0;
        while(!q.empty()){
            int size=q.size();
            cout<<size<<endl;
            for(int i=0;i<size;i++){
                auto node=q.front().first;
                auto cnt=q.front().second;
                q.pop();
                if(i==0){
                    mini=cnt;
                    first=cnt-mini;
                }
                if(i==size-1){
                    sec=cnt-mini;
                    ans=max(ans,sec-first+1);
                }
                
                if(node->left){
                    q.push({node->left,((2*cnt) +1)-mini});
                }
                if(node->right){
                    q.push({node->right,((2*cnt)+2)-mini});
                }

            }
        }
        return ans;

    }
};