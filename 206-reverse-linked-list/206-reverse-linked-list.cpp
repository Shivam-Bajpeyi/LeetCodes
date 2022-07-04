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
        if(head==NULL || head->next==NULL)
            return head;
        
        //change link 1->2 to 1<-2
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        
        while(curr){
            curr->next = prev;  //1<-2
            
            //update pointers
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt->next;
        }
        
        //curr is at NULL, prev at last node
        return prev;
    }
};