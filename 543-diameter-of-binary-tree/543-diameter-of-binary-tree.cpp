//diameter: max value of (lh+rh) for any node in the tree. (may or may not the root) 
class Solution {
public:
    int height(TreeNode* root, int &diameter){
        if(root == NULL) return 0;
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        
        //check and update diameter after knowing the lh & rh for any node
        diameter = max(diameter, lh+rh);
        
        return max(lh, rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root== NULL) return 0;
        
        int diameter = INT_MIN;     //max we want
        height(root, diameter);
        
        return diameter;
    }
};