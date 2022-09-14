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

//DFS + hashmap
class Solution {
public:
    void f(TreeNode* root, unordered_map<int, int> &mpp, int &cnt){
        //at leaf node check, 
        if(root==NULL)
            return;
        
        //add freq of the node
        mpp[root->val]++;
        
        //check PPP on the leaf node 
        if(!root->left && !root->right){
            int flag = 0;
            for(auto it: mpp){
                if(it.second%2){    //odd freq
                    if(flag==0)
                        flag = 1;
                    else{
                        flag = -1;
                        break;
                    }
                       
                }     
            }
            
            if(flag != -1) cnt++;
        }
        
        //DFS- go left and right
        f(root->left, mpp, cnt);
        f(root->right, mpp, cnt);
        
        mpp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mpp;
        int ans = 0;
        f(root, mpp, ans);
        return ans;
    }
};