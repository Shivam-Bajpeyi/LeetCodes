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
    void validPaths(TreeNode* root, int target, vector<int> temp, vector<vector<int>> &res){
        if(root==NULL) return;
        
        //add node->val to the path
        temp.push_back(root->val);
        target -= root->val;
        
        //it should be leaf node
        if(target==0 && !root->left && !root->right){
            res.push_back(temp);
            return;
        }
        
        //explore
        validPaths(root->left, target, temp, res);
        validPaths(root->right, target, temp, res);
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        
        validPaths(root, targetSum, temp, res);
        return res;
    }
};