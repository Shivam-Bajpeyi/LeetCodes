/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//LCA: find any one node out of p or q that can be our LCA surely or if we can find a node where root->left==p and 
//root->right==q then root will be LCA
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) 
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 
        
        //since it is sure that LCA exist, if its not in one part it will be in another one
        if(left==NULL)
            return right;
         
        else if(right==NULL)
            return left;
        
        else
            return root;       //LCA = root when root->left = p & root->right==q

    }
};