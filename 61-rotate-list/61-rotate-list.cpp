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
    int totalNodes(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        
        //step-1: get actual rotation 
        int n = totalNodes(head);
        k = k%n;    //4%3 = 1 rotation we need
        if(k==0)
            return head;
        
        //step-2: point slow to the last node of rotated list
        ListNode* slow = head;
        ListNode* fast = head;
        while(k){
            fast = fast->next;
            k--;
        }
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        //get head of rotated LL
        ListNode* ans = slow->next;
        slow->next = NULL;  //last node
        fast->next = head;  //hook last node to given LL head
        
        return ans;
    }
};