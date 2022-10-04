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
    //traverse every left and right node and check at the leaf if path sum == target
    bool hasPathSum(TreeNode* root, int sum) {
        if(root== NULL)
            return false;
        
        //substract root val from sum
        sum = sum- root->val;  
        
        //check if we reach at leaf(no child further) and sum become 0
        if(sum==0 && root->left==NULL && root->right==NULL)
            return true;          
        
        //return true if at any of the path returns true from the root
        return (hasPathSum(root->left,sum) || hasPathSum(root->right,sum));
       
    }
};