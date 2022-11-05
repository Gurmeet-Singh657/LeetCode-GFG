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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        bool firstpass=true;
        ListNode* prevfirst=NULL;
        while(curr!=NULL)
        {
            ListNode* prev=NULL,*first=curr,*ahead=NULL;
            int count=0;
            while(count<k && curr!=NULL)
            {
                curr=curr->next;
                count++;
            }
            if(count==k)
            {
                curr=first;
                for(int i=0;i<k;i++)
                {
                    ahead=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=ahead;
                }
                if(firstpass==true)
                {
                    firstpass=false;
                    head=prev;
                    prevfirst=first;
                }
                else
                {
                    prevfirst->next=prev;
                    prevfirst=first;
                }
            }
            else
            {
                if(firstpass==false)
                {
                    prevfirst->next=first;
                }
            }
            
        }
        return head;
    }
};