/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next==head)
             return head;
        ListNode* slow=head,*fast=head;
        
        do
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==NULL || fast->next==NULL) return NULL;
        }while(slow!=fast);
        
        if(slow==head) return slow;
        
        slow=head,fast=fast;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow->next;
    }
};