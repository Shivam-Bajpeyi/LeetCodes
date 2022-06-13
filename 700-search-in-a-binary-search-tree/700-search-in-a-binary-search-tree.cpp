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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        
        if(root->val == val)
            return root;
        
        TreeNode* ans = NULL;
        //when root is gretaer than target, take left
        if(root->left && root->val> val)    
            ans = searchBST(root->left, val);
        
        //when root is lesser than target, take right
        if(root->right && root->val < val)
            ans = searchBST(root->right, val);
        
        return ans;
    }
};