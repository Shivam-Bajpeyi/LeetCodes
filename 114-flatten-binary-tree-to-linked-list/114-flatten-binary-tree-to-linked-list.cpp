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
    //use thread: attach left subtree's right most node to the root->right 
    //observation: in the LL, root->right is the right of left subtree's right-most guy
    void flatten(TreeNode* root) {
        while(root){
            //if there is no left, just move right
            if(root->left==NULL)
                root = root->right;
            
            //there is left, attach right most guy of left subtree to the root->right and move left
            else{
                TreeNode* curr= root->left;
                
                //reach to rightmost guy
                while(curr->right)
                    curr = curr->right;
                
                //use thread to attach this guy to root->right
                curr->right = root->right;  //4->5
                
                //attach this left part on right
                root->right = root->left;   //1->2
                root->left = NULL;
                
                //move
                root = root->right;
            }
        }
    }
};