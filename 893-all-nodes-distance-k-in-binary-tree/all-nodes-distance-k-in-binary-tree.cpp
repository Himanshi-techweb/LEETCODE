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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
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
        q.push(target);
        int cnt=0;
        
        vector<int> ans;
        unordered_map<TreeNode*,bool> flag;
        flag[target]=true;
        
        while(!q.empty() ){
            int size=q.size();
            if(cnt==k)break;
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
            
            cnt++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);q.pop();
        }
        return ans;
    }
};