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
    bool findTarget(TreeNode* root, int k) {
        if(root== NULL)
            return false;
        
        //find inorder(its sorted in itself)
        vector<int> nums; 
        inorder(root, nums);
        
        //apply 2 sum to find k target in nums[]
        int start = 0, end = nums.size()-1;
        while(start< end){
            int sum = nums[start] + nums[end];
            if(sum == k)   //k found return true
                return true;
            
            else if(sum< k)
                start++;
            else
                end--;
        }
        
        //if k is not there 
        return false;
    }
    
    void inorder(TreeNode* root, vector<int> &nums){
        if(root== NULL)
            return;
        
        //inorder = left root right
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};