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
    ListNode* deleteMiddle(ListNode* head) {
        //we may have to delete 0th node so make a dummy node -> head
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        //2 pointer + middle node logic
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = dummy;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //leave the node where slow is standing
        prev->next = slow->next;
        return dummy->next;
    }
};