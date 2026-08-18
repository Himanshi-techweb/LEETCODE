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
    ListNode* reverseList(ListNode* head) {
        ListNode* newcurr=NULL;
        ListNode* curr=newcurr;
        ListNode* t=head;
        while(t!=NULL){
            ListNode* st=t->next;
            t->next=curr;
            curr=t;
            if(st==NULL)return t;
            t=st;
            

        }
        return t;

    }
};