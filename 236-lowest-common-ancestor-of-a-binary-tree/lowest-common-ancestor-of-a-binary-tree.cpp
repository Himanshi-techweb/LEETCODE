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
    vector<TreeNode*> check1;
    vector<TreeNode*> check2;
    bool check(TreeNode* root,int x,vector<TreeNode*> &arr){
         if(root==NULL)return false;
         arr.push_back(root);
         if(root->val==x)return true;
         if(check(root->left,x,arr) || check(root->right,x,arr))return true;
         arr.pop_back();
         return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p->val,check1);
        check(root,q->val,check2);
        int i=0;TreeNode* ans=NULL;int j=0;
        while(i<check1.size() &&j<check2.size() && check1[i]==check2[j])  {
            ans=check1[i];
            i++;j++;
        }
        return ans;
    }
};