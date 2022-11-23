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
    void makeInorder(TreeNode* root, vector<int> &in){
        if(root){
            //inorder = left root right
            makeInorder(root->left, in);
            in.push_back(root->val);
            makeInorder(root->right, in);
        }
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        
        //prepare inorder
        vector<int> in;
        makeInorder(root, in);
        
        //find queries soln
        for(auto &it: queries){
            int mn= -1, mx= -1;
            int i= 0;
            
            //take min using lower bound- return value not less than it, not present -> last iterator
            if(in[0]<= it){
                mn = lower_bound(in.begin(), in.end(), it)- in.begin();
                if(mn== in.size()) mn--;    //if the value is not present, return last iterator
                if(in[mn]>it) mn--;         //if the value is greater
            } 
            
            //take max using upper bound- return value greater than it
            if(in.back()>= it){
                mx = upper_bound(in.begin(), in.end(), it)- in.begin();
                if(mx>0 && in[mx-1]==it) mx--;  
            } 
                
            mn = (mn==-1) ? -1 : in[mn];
            mx = (mx==-1) ? -1 : in[mx];
            res.push_back({mn, mx});
        }
        
        return res;
    }
};