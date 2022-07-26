class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            int nxt = -1;
            for(int j=i; j<i+n; j++){
                if(nums[j%n]>nums[i]){
                    nxt = nums[j%n];
                    break;
                }
                    
            }
            ans.push_back(nxt);
        }
        
        return ans;
    }
};