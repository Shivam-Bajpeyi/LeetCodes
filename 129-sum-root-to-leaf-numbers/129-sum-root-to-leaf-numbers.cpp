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
    int ans = 0;
    void f(TreeNode* root, int number){
        if(root==NULL) return;
        
        if(!root->left && !root->right){    //add number at leaf nodes
            ans += (number*10+root->val);
            return;
        }
       
        //do the business
        f(root->left, number*10+root->val);
        f(root->right, number*10+root->val);
        
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return -1;
        f(root, 0);
        
        return ans;
    }
};