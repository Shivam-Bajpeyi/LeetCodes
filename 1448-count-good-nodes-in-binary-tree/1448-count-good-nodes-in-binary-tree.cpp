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

//keep a max value that will help in checking whether a node is good or not.
class Solution {
public:
    int f(TreeNode* root, int mx, int &cnt){
        if(root==NULL) return 0;
        
        //good node condition
        if(root->val>= mx) cnt++;
        mx = max(mx, root->val);
        
        if(root->left) f(root->left, mx, cnt);
        if(root->right) f(root->right, mx, cnt);
        
        return cnt;
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        return f(root, root->val, cnt);
    }
};