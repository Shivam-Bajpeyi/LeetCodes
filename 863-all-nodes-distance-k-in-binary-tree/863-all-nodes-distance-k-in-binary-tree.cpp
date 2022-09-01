/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//BFS + hashmap(to track parent node)
class Solution {
public:
    void makePar(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &par){
        if(root==NULL) return;
        
        if(root->left){
            par[root->left]  = root;
            makePar(root->left, par);
        }
        
        if(root->right){
            par[root->right] = root;
            makePar(root->right, par);
        }
    }
    
    //go in all three directions and take nodes with k=0
    //mark  -1 to the visied nodes
    void takeNodes(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> &par, vector<int> &res){
        if(root==NULL || k<0) return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        
        root->val = -1;     //visited, no need to check in this direction
        
        if(k==0){
            res.push_back(root->val);
            return;
        }
        
        //explore in all three directions that had not been explored previosuly
        if(root->left && root->left->val!= -1)
            takeNodes(root->left, k-1, par, res);
        if(root->right && root->right->val!= -1)
            takeNodes(root->right, k-1, par, res);
        if(par[root] && par[root]->val!= -1)
            takeNodes(par[root], k-1, par, res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //node-> parent
        unordered_map<TreeNode*, TreeNode*> par;
        par[root] = NULL;
        makePar(root, par);
        
        //take the nodes that have distance k from the target node
        vector<int> res;
        takeNodes(target, k, par, res);
        
        return res;
    }
};