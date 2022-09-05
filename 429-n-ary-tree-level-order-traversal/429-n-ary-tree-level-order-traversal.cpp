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
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        //BFS
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);  //store nodes of each level in temp
                
                //store children
                for(auto child: node->children)
                    que.push(child);
            }
            res.push_back(temp);    //store every level
        }
        
        return res;
    }
};