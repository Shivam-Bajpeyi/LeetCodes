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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //merge sort
        //make a new linkedlist with merged nodes(sorted)
        ListNode* head = new ListNode(0, NULL);
        ListNode* curr = head;  //used for forming LL
        
        while(list1 && list2){
            if(list1->val <= list2->val){
                curr->next = new ListNode(list1->val);
                curr = curr->next;
                list1 = list1->next;
            }
            else{
                curr->next = new ListNode(list2->val);
                curr = curr->next;
                list2 = list2->next;
            }
        }
        
        while(list1){
            curr->next = new ListNode(list1->val);
            curr = curr->next;
            list1 = list1->next;
        }
        
        while(list2){
            curr->next = new ListNode(list2->val);
            curr = curr->next;
            list2 = list2->next;
        }
        
        //add NULL node in the last
        curr->next = NULL;
        
        //head= NULL -> [1-> 2-> 3-> NULL]
        return head->next;  //1
    }
};