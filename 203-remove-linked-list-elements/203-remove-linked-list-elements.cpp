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
    ListNode* removeElements(ListNode* head, int val) {
       if(head == NULL)
           return NULL;
        
        //step-1: make three pointers prev, cur, nxt to keep track of previous, current, and next node
        ListNode* prev = new ListNode(NULL);  //previous node (NULL initially)
        ListNode* cur = head;   //current node (pointing to head initially)
        ListNode* nxt = cur->next;  //next node of cur
        
        ListNode* ans = prev;
        //step-2: itereate all over the LL and if at any point cur->val == val, we will remove it by connecting prev node directly to next node in this way node with given val will be left behind 
        while(cur != NULL){
            if(cur->val == val){ //node found that we have to remove
                prev->next = cur->next; //remove the node
                cur = cur->next;
                if(nxt) //if nxt == NULL then don't move the pointer
                    nxt = nxt->next;
                
            }
            else{   //if node is not found, move each pointer 1 step
                prev->next = cur; prev  = prev->next;
                cur = cur->next;
                if(nxt) 
                    nxt = nxt->next;
            }
           
        }
        
        //ans is NULL, next node is first node of LL that's why returning next node of ans
        return ans->next;
    }
};