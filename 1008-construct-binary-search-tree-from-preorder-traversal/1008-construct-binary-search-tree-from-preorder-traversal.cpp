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
    TreeNode* makeTree(int i, int j, vector<int> &preorder){
        if(j<i) return NULL;    
       
        TreeNode* root = new TreeNode(preorder[i]);     //root
        
        //left elemnts < root->val so go to that last node  of left
        int temp = i+1;
        while(temp<preorder.size() && preorder[temp]<preorder[i])
            temp++;
        
        root->left = makeTree(i+1, temp-1, preorder);     //root->left
        root->right = makeTree(temp, j, preorder);      //root->right
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return makeTree(0, n-1, preorder);
    }
};