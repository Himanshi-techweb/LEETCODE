/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int count(ListNode* root){
        int cnt=0;
        while(root){
            cnt++;root=root->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        if(n==1){
            ListNode* curr=head;
            while(curr->next->next)curr=curr->next;
            curr->next=NULL;
            return head;
        } 
        int total=count(head);
        int first=total-n;
        if(first==0){
            return head->next;
        }
        ListNode* curr=head;int cnt=0;
        while(curr){
        cnt++;
        if(cnt==first){
          ListNode* check=curr->next->next;
          curr->next=check;
          return head; 
        }
        curr=curr->next;
       } 
       return head;
    }
};