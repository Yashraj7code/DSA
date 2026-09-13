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
        ListNode* temp=head;
        vector <int> res;
        while(temp!=NULL)
        {
          res.push_back(temp->val);
          temp=temp->next;  
        }

        vector <int> ans;
        // ans.push_back(head->val);
        
        int ptr1=0,ptr2=res.size()-1;
        while(ptr1 <= ptr2)
        {
            ans.push_back(res[ptr1]);
            if(ptr1!=ptr2)
            {
                ans.push_back(res[ptr2]);
            }            
            ptr1++;
            ptr2--;
        }
        temp=head;
        for(int i=0;i<ans.size();i++)
        {
            temp->val=ans[i];
            temp=temp->next;
        }

    }
};