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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        //make 2 heads -> head1 for odd & head2 for even
        ListNode* head1 = head;
        ListNode* head2 = head->next;
        ListNode* curr = head->next;
        
        //make list
        while(head1->next && head2->next){              //odd
            head1->next = head1->next->next;
            head1 = head1->next;
            head2->next = head2->next->next;
            head2 = head2->next;
        }         
            
        head1->next = curr;     //odd last node -> even first node
        return head;
    }
};