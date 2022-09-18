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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        
        queue<TreeNode*> que; //to store level
        que.push(root);
        
        queue<TreeNode*> level_node;
        stack<int> level_data;
        
        //BFS
        int level = 1;
        while(!que.empty()){
            int n = que.size();

            //store level for BFS
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                
                //store odd node and their data
                if(level==1)
                    level_node.push(node);
                if(level==0)
                    level_data.push(node->val); 
            }
            
            //correct odd level
            while(level==0 && !level_node.empty()){
                TreeNode* front = level_node.front();   
                level_node.pop();
                
                // cout<<front->val<<endl;
                front->left->val = level_data.top(); level_data.pop();
                front->right->val = level_data.top(); level_data.pop();
            }
            
            level = !level;
        }
        
        return root;
    }
};