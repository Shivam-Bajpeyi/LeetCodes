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
        
        //decide 1st node
        ListNode* curr = NULL;
        if(list1 && list2 && list1->val <= list2->val){
            curr = list1;
            list1 = list1->next;
        }
        else if(list1 && list2 && list1->val > list2->val){
            curr = list2;
            list2 = list2->next;
        }
        
        ListNode* ans = curr;
        //merge sort: take the next small value node and merge to the curr node
        while(list1 && list2){
            if(list1->val<= list2->val){
                // cout<<list1->val<<endl;
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
            else{
                // cout<<list2->val<<endl;
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        
        //point next to the list which has node left to add
        if(list1 || list2){
            if(curr) 
                curr->next = (list1 != NULL) ? list1: list2;
            else 
                return list1!=NULL? list1: list2;
        }
        
        return ans;
    }
};