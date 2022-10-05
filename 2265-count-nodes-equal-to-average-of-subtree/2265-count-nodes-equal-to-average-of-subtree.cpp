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
//use postorder => left-right-root O(N)
class Solution {
public:
    int ans = 0;
    
    pair<int, int> f(TreeNode* root){
        if(root==NULL) return {0, 0};
        
        auto l = f(root->left);
        int lSum = l.first;
        int lCnt = l.second;
        
        auto r = f(root->right);
        int rSum = r.first;
        int rCnt = r.second;
        
        //do the business
        int sum = lSum + rSum + root->val;
        int cnt = lCnt + rCnt + 1;
        if(sum/cnt == root->val)
            ans++;
        
        return {sum, cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};