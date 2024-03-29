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

//Efficient O(H) space using stack
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void storeLeft(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        storeLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int res = node->val; 
        
        if(node->right){
            storeLeft(node->right);
        }
        
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


//brute sc= o(N) store inorder somewhere
// class BSTIterator {
// public:
//     vector<int> nums;   //prepare inorder in nums
//     int i=0;            //i will work as iterator
    
//     void inorder(TreeNode* root){     //inorder
//         if(root){
//             inorder(root->left);
//             nums.push_back(root->val);
//             inorder(root->right);
//         }   
//     }
    
//     BSTIterator(TreeNode* root) {
//         inorder(root);
//     }
    
//     int next() {
//        return nums[i++]; 
//     }
    
//     bool hasNext() {
//         return i<nums.size();
//     }
// };
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */