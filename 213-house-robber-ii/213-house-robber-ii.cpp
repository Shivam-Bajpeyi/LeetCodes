class Solution {
public:
    int rob(vector<int>& nums) {
        //middle element will be same when we check for the max value, just the thing is either consider first element with nums(excluding last) or considering last element with nums(excluding first).
    //so the solution is find the max amount of money with both the cases and return max b/w these both.
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> temp1;
        vector<int> temp2;
        
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);  //consider last element(leave 1st)
            if(i!=n-1) temp2.push_back(nums[i]);//consider 1st element(leave the last)
        }
        //take the max one
        return max(robCheck(temp1), robCheck(temp2));
    }
    
  int robCheck(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        
		//array indexing is 0 based so  considering <n
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1) //because at index 1 we will go to dp[-1] and thats not allowed to do
                pick += dp[i-2];
            
            int notPick = 0 + dp[i-1];
            
            //take whichever option is better
            dp[i] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
};