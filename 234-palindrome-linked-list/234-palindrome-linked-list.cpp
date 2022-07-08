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
    bool isPalindrome(ListNode* head) {
        //middle + reverse + palindrome
        if(head->next ==NULL)
            return head;
        
        //step-1: reach tp the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //step-2: slow is at middle node, reverse from slow+1 to last node
        slow->next = reverseLL(slow->next);
        slow = slow->next;  //set slow
        
        //step-3: compare slow & head to check palindrome
        while(slow!= NULL){
            // cout<<head->val << " "<< slow->val<<endl;
            if(slow->val != head->val)
                return false;
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;   
        }
        
        return prev;
    }
};