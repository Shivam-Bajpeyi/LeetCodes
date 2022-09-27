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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        
        //BFS
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                //take up last node in every level
                if(i == n-1)
                    res.push_back(curr->val);
            }
        }
        
        return res;
    }
};