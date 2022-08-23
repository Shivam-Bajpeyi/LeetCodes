//maximum path sum: max (ls+rs+node->val) for some node in tree.
class Solution {
public:
    int pathSum(TreeNode* root, int &sum){
        if(root==NULL) return 0;
        
        int ls = max(0, pathSum(root->left, sum));
        int rs = max(0, pathSum(root->right, sum));
        
        //while finding ls and rs, check and update max path sum
        sum = max(sum, ls+rs+root->val);
        
        //max path sum of two subtrees
        return max(ls, rs)+ root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root== NULL) return 0;
        int sum = INT_MIN;
        
        pathSum(root, sum);
        
        return sum;
    }
};