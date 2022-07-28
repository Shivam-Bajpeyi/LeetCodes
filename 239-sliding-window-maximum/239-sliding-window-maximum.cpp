class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int start = 0; //minimum starting point for a window
        
        deque<int> dq;  //maintain decreasing sequence, front() = max element
        int n = nums.size();
        for(int i=0; i<n; i++){
            //step-1: set window starting, by removing redundant index
            if(!dq.empty() && dq.front()<start) dq.pop_front();
            
            //step-2: push element by maintaining decreasing sequence
            while(!dq.empty() && nums[dq.back()]< nums[i])   //1) remove smaller elements of no use
                dq.pop_back();
            dq.push_back(i);    //2) push index
            
            //step-3: when window moving forward, update its starting point & take out max
            if(i >= k-1){
                start++;
                ans.push_back(nums[dq.front()]);  
            }
            
        }
        
        return ans;
    }
};