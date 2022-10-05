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
    void f(TreeNode* root, int level, int depth, int val){
        if(root==NULL) return;
        
        if(level == depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            root->left->left = left;
            root->right->right = right;
            return;
        }
        
        f(root->left, level+1, depth, val);
        f(root->right, level+1, depth, val);
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)    //attach root to the left of val
        {
            TreeNode* cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }
        
        f(root, 1, depth, val);      //root -> depth1
        return root;
    }
};