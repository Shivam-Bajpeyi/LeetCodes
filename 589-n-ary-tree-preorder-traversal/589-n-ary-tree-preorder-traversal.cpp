/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversal(Node* root, vector<int> &res){
        if(root==NULL) return;
        
        res.push_back(root->val);
        
        //call function for each child of root
        for(Node* child: root->children)    //root = 1, children = [3, 2, 4]
            traversal(child, res);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};