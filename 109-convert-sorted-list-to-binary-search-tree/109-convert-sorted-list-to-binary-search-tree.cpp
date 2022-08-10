/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeTree(int low, int high, vector<int>& nums){
        int mid = (low+high)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        if(mid-1 >= low)
            root->left = makeTree(low, mid-1, nums);
        if(high >= mid+1)
            root->right = makeTree(mid+1, high, nums);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        
        return makeTree(0, nums.size()-1, nums);
    }
};