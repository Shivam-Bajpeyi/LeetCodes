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
    bool hasCycle(ListNode *head) {
        //slow and fast pointer approach
        //step-1: make two pointers slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        
        //step-2: move slow 1 step and fast by 2 step
        while(fast != NULL && fast->next!= NULL){
            slow = slow->next;  //move slow by 1 step
            fast = fast->next->next;    //move fast by 2 step
            
            //if there is a cycle somewhere then they will collide at some point definitely so we can return true immediately
            if(slow==fast)   
                return true;
        }
        
        return false;
    }
};