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

//in the last level nodes are left aligned so check leftmost and rightmost edge
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        //calculate height 0f leftmost and rightmost edge
        int lh= 0, rh= 0;
        for(TreeNode* node=root; node; node=node->left) lh++;
        for(TreeNode* node=root; node; node=node->right) rh++;
        
        //if they are equal then every node will have 
        if(lh == rh) return (1<<rh) -1;     //2^(rh) - 1;
        
        //if not, go and calculate nodes for left subtree and right subtree then add 1 to them 
        return 1+ countNodes(root->left)+ countNodes(root->right);
    }
};