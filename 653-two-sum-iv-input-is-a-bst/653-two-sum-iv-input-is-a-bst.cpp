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

//set + dfs: tc= O(N), sc= O(N)
class Solution {
public:
    set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        
        if(st.count(k-root->val)) return true;
        st.insert(root->val);
        
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};