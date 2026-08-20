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
    int total=0;
    pair<ListNode*,ListNode*> reverse(ListNode* root,ListNode* curr){
        ListNode* prev=NULL;
        ListNode* tail=root;
        ListNode* now=root;
        while(now!=curr){
            ListNode* next=now->next;
            now->next=prev;
            prev=now;
            now=next;
        }
        return {prev,tail};
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=1;
        if(head==NULL || head->next==NULL)return head;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            total++;
        }
        k=k%total;
        curr=head;
        while(curr!=NULL && cnt<total-k){
            curr=curr->next;
            cnt++;
        }
        ListNode* nexthead=curr->next;
        auto [start,tail]=reverse(head,nexthead);
        auto [start1,tail1]=reverse(nexthead,NULL);
        tail->next=start1;
        auto [newhead,_]=reverse(start,NULL);
        return newhead;



    }
};