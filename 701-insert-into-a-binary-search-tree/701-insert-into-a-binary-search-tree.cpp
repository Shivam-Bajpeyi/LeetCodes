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
        if(root ==NULL)
            return new TreeNode(val);
        
        //when root is bigger take left
        if(root->left && root->val > val)
            insertIntoBST(root->left, val);
        
        //when root is lesser take right
        if(root->right && root->val< val)
            insertIntoBST(root->right, val);
        
        //if it is placed left, left is null
        if(!root->left && root->val > val)
            root->left = new TreeNode(val);
        
        //if it is placed right, right is null
        else if(!root->right && root->val < val)
            root->right = new TreeNode(val);
        
        return root;
    }
};