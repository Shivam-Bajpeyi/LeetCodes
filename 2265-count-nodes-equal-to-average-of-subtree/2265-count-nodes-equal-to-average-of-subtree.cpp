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
//find avg and check avg==node->val O(N^2)
class Solution {
public:
    int ans = 0;
    int cnt;
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        cnt++;
        return root->val+sum(root->left)+sum(root->right);
    }
    
    int f(TreeNode* root){
        if(root==NULL) return 0;
        
        //do the business
        cnt = 0;
        if(sum(root)/cnt== root->val)
            ans++;
            
        f(root->left);
        f(root->right);
        
        return ans;
    }
    
    int averageOfSubtree(TreeNode* root) {
        return f(root);
    }
};