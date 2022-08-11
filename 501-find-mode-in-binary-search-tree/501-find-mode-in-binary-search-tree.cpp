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
    void getMostFrequentElement(TreeNode* root, unordered_map<int,int> &mpp){
        if(root==NULL)
            return;
        
        mpp[root->val]++;   //increase freq
        
        getMostFrequentElement(root->left, mpp);
        getMostFrequentElement(root->right, mpp);
    }
    
    vector<int> findMode(TreeNode* root) {
        //store frequency of elements using a map 
        unordered_map<int,int> mpp; 
        getMostFrequentElement(root, mpp);
        
        //store most frequent elements in pq
        priority_queue<pair<int, int>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});    
        }
        
        
        //take them out and store in vector<int>
        vector<int> res;
        int mx = pq.top().first;    //top freq
        while(!pq.empty() && pq.top().first==mx){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};