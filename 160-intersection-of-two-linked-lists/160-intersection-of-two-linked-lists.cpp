/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {        //optimal oneih
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        while(d1 || d2 || d1!=d2){
            if(d1==d2)
                return d1;          //return if both are equal; if not intersect: NULL-NULL
            
            if(d1==NULL){            //asssign to another LL, if any of them reaches NULL
                d1 = headB;
                continue;
            }
                
            if(d2==NULL){
                d2 = headA;
                continue;
            }
                
            d1 = d1->next;
            d2 = d2->next;
        }
        return d1;
    }
};