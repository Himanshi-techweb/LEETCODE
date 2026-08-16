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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushleft(TreeNode* root){
        TreeNode* curr=root;
        
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode* front=st.top();
        st.pop();
        if(front->right){
            pushleft(front->right);
        }
        return front->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */