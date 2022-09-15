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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        
        TreeNode* curr = root;
        TreeNode* prev = root;
        while(curr){
            prev = curr;
            if(curr->val< val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        if(prev->val> val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
        
        return root;
    }
};