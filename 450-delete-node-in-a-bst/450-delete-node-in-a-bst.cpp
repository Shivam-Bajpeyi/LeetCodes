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
    TreeNode* deleteKey(TreeNode* root, int key){
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

    TreeNode* deleteNode(TreeNode* node, int key) {
        if(node== NULL) return node;
        
        if(node->val ==key)
            return deleteKey(node, key);
        
        TreeNode* root = node;
        //find and delete node
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = deleteKey(root->left, key);
                    break;
                } 
                else
                    root = root->left;
            } 
            
            else{
                if(root->right && root->right->val == key){
                    root->right = deleteKey(root->right, key);
                    break;
                }
                else
                    root = root->right;
            }
        }
    
        return node;
    }
};