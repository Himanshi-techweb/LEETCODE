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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int n=curr1->val + curr2->val;
        int r=n%10;
        n=n/10;
        ListNode* ans=new ListNode(r);
        ListNode* curr=ans;
        curr1=curr1->next;
        curr2=curr2->next; 
        while(curr1 && curr2){
            int n1=curr1->val;
            int n2=curr2->val;
            int sum=n+n1+n2;
            r=sum%10;
            n=sum/10;
            ListNode* node=new ListNode(r);
            curr->next=node;
            curr=node;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int sum=n+curr1->val;
            r=sum%10;
            n=sum/10;
            ListNode* node =new ListNode(r);
            curr->next=node;
            curr=node;
            curr1=curr1->next;

        }
        while(curr2){
            int sum=n+curr2->val;
            r=sum%10;
            n=sum/10;
            ListNode* node= new ListNode(r);
            curr->next=node;
            curr=node;
            curr2=curr2->next;

        }
        while(n>0){
            r=n%10;
            n=n/10;
            ListNode* node=new ListNode(r);
            curr->next=node;
            curr=node;
        }
        return ans;
    }
};