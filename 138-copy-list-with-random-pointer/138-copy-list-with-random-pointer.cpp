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
        //store original node and corresponsing copy node(with same val) in hashamap
        unordered_map<Node*, Node*> mpp;
        Node* ptr = head;
        
        while(ptr){
            mpp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        //assign next and random to copy nodes
        ptr = head;
        while(ptr){
            mpp[ptr]->next = mpp[ptr->next];
            mpp[ptr]->random = mpp[ptr->random];
            ptr = ptr->next;
        }
        
        //return copy node of head
        return mpp[head];   
    }
};