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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //map<vertical, map<level, multiset<int>>>
        map<int, map<int, multiset<int>>> mpp;  //to store nodes with vertical & level
        queue<pair<TreeNode*, pair<int, int>>> que;
        
        //initial configuration
        que.push({root, {0, 0}});   //root, vertical=0, level=0
        
        //step-1: BFS to assign vertical & level and store the node info in map
        while(!que.empty()){
            int n = que.size();
            
            for(int i=0; i<n; i++){
                auto it = que.front();
                que.pop();
                TreeNode* node = it.first;
                int x = it.second.first;     //vertical
                int y = it.second.second;    //level
            
                mpp[x][y].insert(node->val);   //mpp[vertical][level] = node->val;
                
                if(node->left)
                    que.push({node->left, {x-1, y+1}});
                if(node->right)
                    que.push({node->right, {x+1, y+1}});
            }
        }
        
        //extract information stores in map and return in 2d vector
        vector<vector<int>> ans;
        for(auto &it: mpp){         //vertical, (levels, nodes)
            vector<int> temp;
            for(auto &jt: it.second){      //level, nodes
                temp.insert(temp.end(), jt.second.begin(), jt.second.end());
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};