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

//ans = min(ans, currentString)
class Solution {
public:
    string ans = "~";  //infinity string
    void f(TreeNode* root, string str){
        if(root==NULL) return;
        
        if(!root->left && !root->right){    //add number at leaf nodes
            ans = min(ans, char(root->val+'a')+str);
            return;
        }
       
        //do the business
        f(root->left, char(root->val+'a')+str);
        f(root->right, char(root->val+'a')+str);
        
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        f(root, "");
        return ans;
    }
};