/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findroot(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &arr){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          TreeNode* front=q.front();
          q.pop();
          if(front->left){
            q.push(front->left);
            arr[front->left]=front;
          }
          if(front->right){
            q.push(front->right);
            arr[front->right]=front;
          }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)return {};
       unordered_map<TreeNode*,TreeNode*> parent;
       queue<TreeNode*> q;
       findroot(root,parent);
       unordered_set<TreeNode*> visi;
       q.push(target);
       visi.insert(target);
       int x=0;
       while(!q.empty()){
        int size=q.size();
        if(x==k)break;
        for(int i=0;i<size;i++){
          TreeNode* front=q.front();
          q.pop();
           TreeNode* el=parent[front];
          if(front->left && visi.find(front->left)==visi.end()){
            TreeNode* left=front->left;
             visi.insert(left);
             q.push(left);
          }
          if(front->right && visi.find(front->right)==visi.end()){
            TreeNode* right=front->right;
             visi.insert(right);
             q.push(right);
          }
          if(front!=root && visi.find(el)==visi.end()){
             visi.insert(el);
             q.push(el);
          }
        }x++;
       }
       vector<int> ans;
       while(!q.empty()){
         ans.push_back(q.front()->val);
         q.pop();
       }
       return ans;
    }
};