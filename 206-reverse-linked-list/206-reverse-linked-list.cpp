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
        if(head == NULL || head->next ==NULL)
            return head;
        
        //step-1: make 3 pointers
        ListNode* prev = NULL;
        ListNode* cur= head;
        ListNode*nxt = cur->next;
        
        //step-2: iterate over LL and make connections backward
        while(cur != NULL){
            cur->next = prev; //made connection backward
            //setup pointers at new positions
            prev =cur;
            cur = nxt;
            if(nxt) nxt = nxt->next;
        }
        
        //in the last cur will be at NULL and prev at last node so return last node as head
        return prev;
    }
};