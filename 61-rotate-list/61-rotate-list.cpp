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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        
        //step-1: get actual rotation
        ListNode* curr = head;
        ListNode* prev = new ListNode();
        int n = 0;
        while(curr){
            n++;
            prev = curr;
            curr = curr->next;
        }
        
        k = k%n;    //4%3 = 1 rotation we need
        if(k==0)
            return head;
        
        //step-1: hook last node of given LL to the head
        prev->next = head;
        
        //step-2: get new head decide last node for the new LL
        ListNode* newH = new ListNode();
        k = n-k-1;  //traverse k times to reach last node
        while(k){
            head = head->next;
            k--;
        }
        
        newH = head->next;  //new head
        head->next = NULL;  //last node
        
        return newH;
    }
};