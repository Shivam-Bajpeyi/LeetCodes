class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        //push all items in 
        for(auto it: nums)
            pq.push(it);
        
        //get kth largest elememt from the top
        while(--k){
            pq.pop();
        }
        
        return pq.top();
    }
};