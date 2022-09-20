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
//node = (min, max)
class Solution {
public:
    bool isValid(TreeNode* root, long mn, long mx){
        if(root==NULL) return true;
        
        if(root->val <=mn || root->val>= mx)
            return false;
        
        //both side should return true
        return (isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx));
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};