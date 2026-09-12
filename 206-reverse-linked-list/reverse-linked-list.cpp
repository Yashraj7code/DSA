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
       ListNode * prev;
       ListNode * curr;
       ListNode * new1;
       prev=NULL;
       curr=head;
       if(head==NULL)
       {
        return NULL;
       }
       new1=head->next;
       while(new1!=NULL)
       {
        curr->next=prev;
        prev=curr;
        curr=new1;
        new1=new1->next;
       } 
       curr->next=prev;
       head=curr;
       return head;
    }
};