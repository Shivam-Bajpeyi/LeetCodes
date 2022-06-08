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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        
        //step-1: make three pointers prev, cur, and nxt
        ListNode* prev = new ListNode(NULL);  //point to previous node of cur, initially NULL
        prev->val = 101;    //-100 <= val <= 100
        ListNode* cur = head;   //point to current node, initially head of LL
        ListNode* nxt = cur->next;  //point to next node of cur
        
        prev->next = cur;   //connect prev->next link to cur
        ListNode* ans = prev;   //helps in returning head of final LL
        
        //step-2: iterate over the LL to remove dupliacte node
        while(cur != NULL){
            //step-3: duplicate node found, remove it
            if(prev->val == cur->val){   
                prev->next = nxt;   //make connection to next node, in this way duplicate node will removed from LL
                cur = nxt;
                if(nxt) nxt = nxt->next;
                
            }
            
            else{   //move pointers 1 step ahead
                prev = prev->next;
                cur = cur->next;
                if(nxt) nxt = nxt->next;
            }
        }
        //return head of this final LL
        return ans->next;
    }
};