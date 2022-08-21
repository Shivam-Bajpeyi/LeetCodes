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
        //slow-fast pointer approach
        ListNode* slow = head;
        ListNode* fast = head;
        
        //move them to see if they matches
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL)  //no cycle, pointer will reach to end
            return NULL;
        
        //if there is cycle, detect where is it
        fast = head;    //place head at head
        
        //move 1 step untill they match
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};