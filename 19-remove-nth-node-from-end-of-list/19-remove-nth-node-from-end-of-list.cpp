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
        if(head->next ==NULL)
            return NULL;
        
        //2 pointers approach
        //step-1: count total nodes
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        
        //(5- 2) = k = 3
        //trverse k nodes and delete the node
        int k = cnt - n;
        curr = head;
        
        //when head we need to delete: k = 5-5
        if(k==0)    //first node
            return head->next;
        
        while(k){ // 3 2 1 
            if(k==1)
                curr->next = curr->next->next;
            k--;
            curr= curr->next;
        }
        
        return head;
    }
};