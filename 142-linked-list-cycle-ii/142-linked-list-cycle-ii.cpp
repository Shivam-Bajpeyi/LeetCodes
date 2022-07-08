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
        ListNode* slow = head;
        ListNode* fast = head;
        
        //if they meet at some point there is cycle
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast)
                break;
        }
        
        if(fast==NULL || fast->next==NULL)
            return NULL;
        
        //point fast at head and move both by 1 step
        fast = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};