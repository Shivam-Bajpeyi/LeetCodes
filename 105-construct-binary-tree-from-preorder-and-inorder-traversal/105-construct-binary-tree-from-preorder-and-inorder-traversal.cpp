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

//preorder = root [left] [right]
//inorder  = [left] [root] [right] 

//find root in inorder and accordingly go for root->left = [left] and root->right = [right]
class Solution {
public:
    TreeNode* treeMaker(int inStart, int inEnd, vector<int> &inorder, int preStart, int preEnd, vector<int> &preorder, unordered_map<int, int> &inMap){
        // if(inStart > inEnd) return NULL;
        
        //find root index to decide how many elements will be on left and right to root
        int rootInd = inMap[preorder[preStart]];
        
        //make root of the tree
        TreeNode* root = new TreeNode(inorder[rootInd]);
        
        //elements left to root
        int numsLeft = rootInd- inStart;
        //if there is no element left for the left child attach NULL to it
        root->left = (numsLeft==0)? NULL : treeMaker(inStart, rootInd-1, inorder, preStart+1, preStart+numsLeft, preorder, inMap);
        
        //elements right to root
        int numsRight = inEnd- rootInd;
         //if there is no element left for the right child attach NULL to it
        root->right = (numsRight==0)? NULL : treeMaker(rootInd+1, inEnd, inorder, preStart+numsLeft+1, preEnd, preorder, inMap);
            
        //return root of this tree
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //store inorder elememt's index
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        //make tree
        TreeNode* root = treeMaker(0, inorder.size()-1, inorder, 0, preorder.size(), preorder, inMap);
        
        //return its node
        return root;
    }
};