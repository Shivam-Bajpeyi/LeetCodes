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
        //merge sort solution
        vector<int> nums;
        
        //step-1: merge LL1 & LL2 and store them in nums using merge sort
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){   //whichever node is smaller pick that
                nums.push_back(list1->val);
                list1 = list1->next;    //move pointer to the next node
            }
            
            else{
                nums.push_back(list2->val);
                list2 = list2->next;
            }   
        }
        
        //if any of LLs' nodes are remaining, store them too
        while(list1 != NULL){   //if LL1 nodes left
            nums.push_back(list1->val);
            list1 = list1->next;
        }
        
        while(list2 != NULL){
            nums.push_back(list2->val);
            list2 = list2->next;
        }
        
        //step-2: make a new LL of this ans vector to return as answer
        ListNode* ans = new ListNode(NULL);
        ListNode* cur = ans;    //cur will be used to make the LL
        for(int i=0; i<nums.size(); i++){
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        
        //step-3: We have made ans NULL and its next node is pointing to the first node of our ans LL, that's why ans->next
        return ans->next;
    }
};