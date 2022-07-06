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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //using 2 pointers
        ListNode* start = new ListNode();
        start->next = head; //if they ask to delete head (n= number of nodes)
        
        //2 pointers
        ListNode* fast = start;
        ListNode* slow = start;
        for(int i=1; i<=n; i++) //move fast n steps ahead
            fast = fast->next;
        
        //move them together untill fast reaches the last node
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        //slow reached at prev node of that we have to delete
        slow->next = slow->next->next;
        
        return start->next;
    }
};