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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        
        vector<int> res;
        postorder(res, root);
        
        //since res has the postorder traversal
        return res;
    }
    
    void postorder(vector<int> &res, TreeNode* root){
        if(root==NULL)
            return;
        
        //postorder: left - right - root
        postorder(res, root->left);
        postorder(res, root->right);
        res.push_back(root->val);
    }
};