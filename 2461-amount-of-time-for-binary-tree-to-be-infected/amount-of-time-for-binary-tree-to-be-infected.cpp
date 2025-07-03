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
    TreeNode* find(TreeNode* root,int start){
        if(root==NULL)return root;
        if(root->val==start)return root;
        TreeNode* left= find(root->left,start);
        if(left)return left;
        return find(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> top;
        queue<TreeNode*> q;
        q.push(root);
        top[root]=NULL;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                top[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                top[node->right]=node;
            }
        }
        
        


        unordered_set<TreeNode* > st;
        TreeNode* start_node=find(root,start);
        queue<TreeNode*> check;
        check.push(start_node);
        int cnt=0;
        while(!check.empty()){
            int size=check.size();
            if(size>0)cnt++;
            for(int i=0;i<size;i++){
                TreeNode* front=check.front();
                st.insert(front);
                check.pop();
                if(front->left && st.find(front->left)==st.end())check.push(front->left);
                if(front->right && st.find(front->right)==st.end())check.push(front->right);
                if(top[front]!=NULL && st.find(top[front])==st.end())check.push(top[front]);
            }
           
        }
        return cnt-1;
    }
};