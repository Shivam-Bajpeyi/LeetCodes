//kadane's Algorithm O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        int ans = INT_MIN;
        int sum = 0;
        
        //iterate over the array
        for(int i=0; i<n; i++){
            sum += nums[i]; //do the sum
            ans = max(ans, sum);
            
             //make sum = 0, because -ve values will not give us largest sum
            if(sum< 0)
                sum = 0;
        }
        
        return ans;
    }
};