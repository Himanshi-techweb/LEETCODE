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
    // int amountOfTime(TreeNode* root, int start) {
        
    // }
    TreeNode* findnode(TreeNode* root,int start){
        if(root==NULL)return NULL;
        if(root->val==start)return root;
        TreeNode* left=findnode(root->left,start);
        if(left)return left;
        TreeNode* right=findnode(root->right,start);
        if(right)return right;
        return NULL;
    }
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
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL)return {};
       unordered_map<TreeNode*,TreeNode*> parent;
       queue<TreeNode*> q;
       findroot(root,parent);
       unordered_set<TreeNode*> visi;
       TreeNode* target=findnode(root,start);
       q.push(target);
       visi.insert(target);
       int x=0;
       while(!q.empty()){
        int size=q.size();
        //if(x==k)break;
        x++;
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
        }
       }
    //    vector<int> ans;
    //    while(!q.empty()){
    //      ans.push_back(q.front()->val);
    //      q.pop();
    //    }
       return x-1;
    }
};