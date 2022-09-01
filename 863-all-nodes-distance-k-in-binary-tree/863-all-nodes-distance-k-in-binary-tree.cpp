/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//BFS + hashmap

class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track); 
        
        //2nd BFS to find all the nodes at k dist.
        int dist = 0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        visited[target] = true;
        queue.push(target);
        while(true){
            if(dist++ == k)
                break;
            
            int size = queue.size();
            for(int i=0; i<size; i++){
                TreeNode* node = queue.front(); 
                queue.pop();
                
                //upper
                if(parent_track[node] && !visited[parent_track[node]]){
                    queue.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
                    
                if(node->left && !visited[node->left]){
                    queue.push(node->left);
                    visited[node->left] = true;
                }
                    
                if(node->right && !visited[node->right]){
                    queue.push(node->right);
                    visited[node->right] = true;
                }       
            }  
        }
     
        
        //put back nodes at dist. k from queue to vector
        vector<int> ans;
        int size = queue.size();
        while(!queue.empty()){
            ans.push_back(queue.front()->val);
            queue.pop();
        }
        
        return ans; 
    }
};