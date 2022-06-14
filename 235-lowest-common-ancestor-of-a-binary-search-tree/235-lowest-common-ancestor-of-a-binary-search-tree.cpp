/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while(true){
        int cur = root->val;
        if(p->val < cur && q->val < cur)    //go left
            root = root->left;
        
        else if(p->val > cur && q->val > cur) //go right
            root = root->right;
        
        else{   //any of the two node has matched, return whoever is come first that will be LCA
            ans = root;
            break;
        }
      }
        
        return ans;
    }
};