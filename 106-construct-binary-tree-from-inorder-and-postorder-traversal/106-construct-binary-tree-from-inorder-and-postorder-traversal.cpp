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

//postorder = [left] [right] root 
//inorder  = [left] [root] [right] 
//find root in inorder(last element of postorder) and accordingly go for root->left = [left] and root->right = [right]

class Solution {
public:
    TreeNode* treeMaker(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, unordered_map<int, int> &inMap){
        // if(inStart > inEnd) return NULL;
        
        //find root index(last elment in postorder) to decide how many elements will be on left and right to root
        int rootInd = inMap[postorder[postEnd]];
        
        //make root of the tree
        TreeNode* root = new TreeNode(inorder[rootInd]);
        
        //elements left to root
        int numsLeft = rootInd- inStart;
        //if there is no element left for the left child attach NULL to it
        root->left = (numsLeft==0)? NULL : treeMaker(inStart, rootInd-1, inorder, postStart, postStart+numsLeft-1, postorder, inMap);
        
        //elements right to root
        int numsRight = inEnd- rootInd;
         //if there is no element left for the right child attach NULL to it
        root->right = (numsRight==0)? NULL : treeMaker(rootInd+1, inEnd, inorder, postStart+numsLeft, postEnd-1, postorder, inMap);
            
        //return root of this tree
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //store inorder elememt's index
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        //make tree
        TreeNode* root = treeMaker(0, inorder.size()-1, inorder, 0, postorder.size()-1, postorder, inMap);
        
        //return its node
        return root;
    }
};