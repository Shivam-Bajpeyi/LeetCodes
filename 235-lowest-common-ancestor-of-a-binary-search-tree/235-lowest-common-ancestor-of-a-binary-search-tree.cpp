//use the property of BST, if any one of the node is find then definitely another will be in that subtree and if at any point left and right is in different parts that means root is the LCA.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        
        if(root->val> p->val && root->val> q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        else if(root->val< p->val && root->val< q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};