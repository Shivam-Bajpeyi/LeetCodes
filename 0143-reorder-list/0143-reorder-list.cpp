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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;    //store nodes to access last nodes
        ListNode* node  = head;
        int cnt = 0;
        while(node){
            st.push(node);
            node= node->next;
            cnt++;
        }
        
        if(cnt<=2) return;
        
        ListNode* pptr = head;
        for (int j=0; j<cnt/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = st.top();
            st.pop();
            element->next = pptr->next;
            pptr->next = element;
            
            // cout<<pptr->val<<" "<<pptr->next->val<<" "<<pptr->next->next->val<<endl;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
        
    }
};