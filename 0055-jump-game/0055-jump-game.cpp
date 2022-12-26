//DP memoization soln = dp[n, 0]
class Solution {
public:
    int check(int ind, vector<int> &nums,  vector<int> &dp){
        if(ind>=nums.size()-1)
            return true;
        if(nums[ind] ==0)
            return false;
        
        if(dp[ind] != -1) 
            return dp[ind];
        
        //explore
        int n = nums[ind];          //2
        while(n){
            //take jumps 2, 1 from the current index
            if(check(ind+n, nums, dp))
                return dp[ind] =true;
            n--;
        }
        
        return dp[ind] =false;
    }
    
    bool canJump(vector<int>& nums) {
        
        //if there is no point where we will not jump, reach to target- True
        int flag = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) flag = 0;
            if(i== nums.size()-1 && flag ==1)
                return true;       
        }
        
        int n = nums.size();
        vector<int> dp(n, -1);
        return check(0, nums, dp);
    }
};