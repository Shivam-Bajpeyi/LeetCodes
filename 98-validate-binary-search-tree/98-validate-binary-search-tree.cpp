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
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);   //root can be any value(INT_MIN, INT_MAX)
    }
    
    bool check(TreeNode* root, long mn, long mx){
        if(root== NULL) //if reached to the leaf node, that means this path is following property of BSt
            return true;
        
        if(root->val <= mn || root->val >=mx) //if root is not following condition, return false
            return false;
        
        //check left and right child of the node with updated limits.(min limit, max limit)
        return (check(root->left, mn, root->val) && check(root->right, root->val, mx));
    }
};