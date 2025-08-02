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
    long long len=INT_MIN;
    //2*i +1 ==left and 2*i +2==right
    int widthOfBinaryTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return 1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long start=q.front().second;long long e=0;
            for(long long i=0;i<size;i++){
               auto front=q.front();TreeNode* node=front.first;int k=front.second;
               q.pop();
            //    if(i==0)start=front.second;
               if(i==size-1)e=front.second;
               if(node->left){
                q.push({node->left,(long long)2*k+1-start});
               }
               if(node->right){
                q.push({node->right,(long long)2*k+2-start});
               }
            }
            len=max(len,(long long)e-start+1);
        }
        return len;
    }
};