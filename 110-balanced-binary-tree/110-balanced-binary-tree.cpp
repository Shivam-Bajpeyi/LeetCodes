/*height function will return-- 
1) -1 if tree is not balanced at some point (absolute difference of heights of left and right subtree is more than 1) and
2) height of the node if it does not violates the condition*/

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        //check left subtree
        int left = height(root->left);
        if(left == -1) return -1;
        
        //check right subtree
        int right = height(root->right);
        if(right == -1) return -1;
        
        //if it violates the rule => not balanced
        if(abs(left-right) >1) return -1;   
        
        //else return max height from the node        
        return max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return (height(root) != -1);   //if function is returning height of root=> balanced
    }
};