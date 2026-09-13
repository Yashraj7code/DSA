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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return ;
        }
        // ListNode* temp=head;
        // vector <int> res;
        // while(temp!=NULL)
        // {
        //   res.push_back(temp->val); /// space complexity -> O(n) 
        //   temp=temp->next;  
        // }

        // vector <int> ans;
        // // ans.push_back(head->val);
        
        // int ptr1=0,ptr2=res.size()-1;
        // while(ptr1 <= ptr2)
        // {
        //     ans.push_back(res[ptr1]);
        //     if(ptr1!=ptr2)
        //     {
        //         ans.push_back(res[ptr2]);
        //     }            
        //     ptr1++;
        //     ptr2--;
        // }
        // temp=head;
        // for(int i=0;i<ans.size();i++)
        // {
        //     temp->val=ans[i];
        //     temp=temp->next;
        // }
        //this is in space complexity of O(1);


        //O(n) && O(1) approach
        // 1-> find middle
        // 2-> reverse second half
        // 3->join both part alternatively

        ListNode* slow=head;
        ListNode* fast=head;
        //findng middle
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //slow is last node of first half
        ListNode* second=slow->next;
        slow->next=NULL;
        
        //reversing second half
        ListNode* prev=NULL;
        ListNode* curr=second;

        while(curr!=NULL)
        {
            ListNode * next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        second=prev;

        //merging two halves

        ListNode* first=head;

        while(second!=NULL)
        {
            ListNode* firstnext=first->next;
            ListNode* secondnext=second->next;
            first->next=second;
            second->next=firstnext;

            first=firstnext;
            second=secondnext;
        }


    }
};