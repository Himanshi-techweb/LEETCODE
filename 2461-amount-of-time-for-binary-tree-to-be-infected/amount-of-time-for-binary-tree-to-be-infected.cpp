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
    TreeNode* target;
    void solve(TreeNode* root,int t){
        if(root==NULL)return ;
        if(root->val==t){
            target=root;return;
        }
        solve(root->left,t);
        solve(root->right,t);
        
    }
    int amountOfTime(TreeNode* root, int t) {
        unordered_map<TreeNode* ,TreeNode*>st;
        queue<TreeNode*> q;
        q.push(root);
        st[root]=new TreeNode(-1);
        while(!q.empty()){
            auto front=q.front();q.pop();
            if(front->left){
                q.push(front->left);
                st[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                st[front->right]=front;
            }
        }
        solve(root,t);
        q.push(target);
        int cnt=0;
        
        vector<int> ans;
        unordered_map<TreeNode*,bool> flag;
        flag[target]=true;
        
        while(!q.empty() ){
            int size=q.size();
            cnt++;
            for(int i=0;i<size;i++){
                auto front=q.front();q.pop();
                //try it child
                if(front->left && !flag.count(front->left)){
                    q.push(front->left);
                    
                    flag[front->left]=true;
                }
                if(front->right && !flag.count(front->right)){
                    q.push(front->right);
                    
                    flag[front->right]=true;
                }
                //try it parent
                TreeNode* back=st[front];
                if(back->val!=-1 && !flag.count(back)){
                    q.push(back);
                    
                    flag[back]=true;
                }
            }
            
            
        }
        
        return cnt-1;
    }
};