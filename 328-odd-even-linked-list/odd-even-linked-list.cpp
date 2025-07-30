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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return head;
        ListNode* odd=new ListNode(-1);
        ListNode* oddhead=odd;
        ListNode* even=new ListNode(-1);
        ListNode* evenhead=even;
        ListNode* curr=head;ListNode* curr2=NULL;
        bool isodd=true;
        while(curr!=NULL){
            if(isodd){
                odd->next=curr;
                odd=odd->next;
            }
            else{
                even->next=curr;
                even=even->next;
            }
             curr=curr->next;
             isodd=!isodd;
        }
        even->next=NULL;
        odd->next=evenhead->next;
        return oddhead->next;

    }
};