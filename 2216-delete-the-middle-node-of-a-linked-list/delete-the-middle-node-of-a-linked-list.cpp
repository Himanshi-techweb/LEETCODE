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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        if(head->next->next==NULL){
            ListNode* curr=head->next;
            delete curr;
            head->next=NULL;
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* curr=NULL;
        while(fast && fast->next){
            curr=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* todelete=slow;
        curr->next=slow->next;
        delete todelete;
        return head;
        


    }
};