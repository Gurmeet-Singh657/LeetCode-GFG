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
    ListNode* myhead;
    map<int,ListNode*> mp;
    int len=0;
    Solution(ListNode* head) {
        myhead=head;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            mp[len]=curr;
            curr=curr->next;
            len++;
        }
    }
    
    int getRandom() {
        int index=rand()%len;
        return mp[index]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */