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
    TreeNode* f(TreeNode* root, int key){
        if(root==NULL) return root;
        
        //return the key node after modification
        if(root->val ==key){
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else{
                TreeNode* right = root->right;
                TreeNode* leftmost = right;
                
                //go to leftmost node of right
                while(leftmost->left != NULL)
                    leftmost = leftmost->left;
                
                //attach left part to it
                leftmost->left = root->left;
                return right;
            }
        }
        
        if(root->val> key) 
            root->left = f(root->left, key);
        else 
            root->right = f(root->right, key);
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return f(root, key);
        // return root;
    }
};