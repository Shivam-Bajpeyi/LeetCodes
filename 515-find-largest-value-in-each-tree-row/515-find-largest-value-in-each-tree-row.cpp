/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<int> res;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            int mx = INT_MIN;
            
            //store each node of the same level and store their left n right node(next level)
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                mx = max(mx, node->val);
                
                //next level nodes
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(mx);    //store level traversal to res
        }
        
        return res;
    }
};