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
        while(root!=NULL){
            cnt++;
            root=root->next;
        }
    }
    ListNode* reverse(ListNode* root){
        ListNode* prev=NULL;
        ListNode* curr=root;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL ||( head->next->next!=NULL && head->next->next==NULL &&  head->next->val==head->next->next->val))return true;
        count(head);
        int half=cnt/2;
        ListNode* curr=head;
        for(int i=0;i<half-1;i++){
            curr=curr->next;
        }
        ListNode* node=curr->next;
        if(cnt%2!=0){
            node=curr->next->next;
        }
        ListNode* newcurr=reverse(node);
    
        curr=head;
        while(newcurr!=NULL){
            if(curr->val!=newcurr->val)return false;
            curr=curr->next;
            newcurr=newcurr->next;

        }
        return true;

    }
};