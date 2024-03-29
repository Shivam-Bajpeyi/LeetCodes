/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        
        queue<Node*> q;
        q.push(root);
        
        //BFS
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                //assign next pointer in a level(next node)
                if(i != n-1)
                    curr->next = q.front();
                else
                    curr->next = NULL;
            }
        }
        
        return root;
    }
};