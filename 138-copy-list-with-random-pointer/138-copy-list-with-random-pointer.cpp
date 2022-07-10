/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        
        //step-1: make copy node and place it next of every node
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            Node* nxt = curr->next;
            curr->next = node;
            node->next = nxt;
            curr = nxt;
        }
        
        //step-2: assign random pointer curr->next->random = curr->random->next
        curr = head;
        while(curr){
            if(curr->random ==NULL)
                curr->next->random = NULL;
            else
                curr->next->random = curr->random->next;
            
            curr = curr->next->next;
        }
        
        //step-3: extarct copy list and make original as it it
        curr = head;
        Node* dummy = new Node(0);
        dummy->next = curr->next;
        
        while(curr->next->next){
            Node* nxt = curr->next->next;
            curr->next->next = nxt->next;
            curr->next = nxt;
            curr = nxt;
        }
        curr->next = NULL;  //last node->NULL
        
        return dummy->next;
    }
};