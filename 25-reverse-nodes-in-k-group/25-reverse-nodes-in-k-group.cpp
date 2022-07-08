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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy;
        ListNode* nxt = dummy;
        
        //count nodes
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        
        //reverse k groups of nodes
        while(cnt>= k){
            curr = prev->next;
            nxt = curr->next;
            
            for(int i=1; i<k; i++){ //for 3 nodes, change 2 links 1->2->3
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            
            //k=3
            cnt = cnt- k;
            
            //assign a new prev
            prev = curr;
        }
        
        return dummy->next;
    }
};