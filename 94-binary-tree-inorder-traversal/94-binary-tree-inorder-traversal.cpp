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
    //Morris Inorder
    vector<int> inorderTraversal(TreeNode* root) {
        if(root== NULL) return {};
        vector<int> res;
        
        while(root != NULL){
            if(root->left == NULL){
                res.push_back(root->val);
                root = root->right;
            } 
            
            else{
                //go to the rightmost guy of the left subtree
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root)
                    curr = curr->right;
                
                //if there is not a thread, make it and move to the left
                if(curr->right == NULL){    
                    curr->right = root;     //make the thread
                    root = root->left;
                }
                
                //if there is already a thread, remove it, push(root) and move right
                else{
                    curr->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                } 
            } 
        }
        
        return res;
    }
};