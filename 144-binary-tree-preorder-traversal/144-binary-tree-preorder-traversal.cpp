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
    //Preorder = root - left - right
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        
        vector<int> res;
        preorder(res, root);
        //return res contains preorder traversal of the tree
        return res;
    }
    
    void preorder(vector<int> &res, TreeNode* root){
        if(root==NULL)
            return;
        
        //preorder: root-left-right
        res.push_back(root->val);   //root
        preorder(res, root->left);  //left
        preorder(res, root->right); //right
    }
};