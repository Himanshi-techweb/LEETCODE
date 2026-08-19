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
    int cnt=0;
    void count(ListNode* root){
        while(root){
            cnt++;
            root=root->next;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        count(head);
        int exact=cnt-n;
        if(exact==0)return head->next;
        ListNode* curr=head;
        cnt=1;
        while(curr && cnt<exact ){
           curr=curr->next;
           cnt++;
        }
        if(curr->next!=NULL){
            curr->next=curr->next->next;
        }
        else  curr->next=NULL;
        return head;
    }
};