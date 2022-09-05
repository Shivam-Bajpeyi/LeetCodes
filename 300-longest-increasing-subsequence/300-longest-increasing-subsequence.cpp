//pick- notPick

//1. recursion
// class Solution {
// public:
//     int f(int ind, int prev, vector<int>& nums){
//         if(ind== nums.size())
//             return 0;
        
//         //notPick- pick
//         int notPick = 0+ f(ind+1, prev, nums);
        
//         int pick = 0;
//         if(prev==-1 || nums[ind]> nums[prev])
//             pick = 1+ f(ind+1, ind, nums);
        
//         //max out of it 
//         return max(notPick, pick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         return f(0, -1, nums);    //f(ind, prev_ind)
//     }
// };


//2. DP memoization: dp[n][n]
// class Solution {
// public:
//     int f(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
//         if(ind== nums.size())
//             return 0;
        
//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
//         //notPick- pick
//         int notPick = 0+ f(ind+1, prev, nums, dp);
        
//         int pick = 0;
//         if(prev==-1 || nums[ind]> nums[prev])
//             pick = 1+ f(ind+1, ind, nums, dp);
        
//         //max out of it 
//         return dp[ind][prev+1] = max(notPick, pick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         //dp[n][n+1]: 1- based index to deal with prev = -1;
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
//         return f(0, -1, nums, dp);    //f(ind, prev_ind)
//     }
// };


//3. Tabulation: using dp[n][n+1]
//ind = n-1 to 0 and prev = ind-1 to -1 (1-based: -1->0)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         //dp[n+1][n+1]: 1- based index to deal with prev = -1;
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
//         for(int ind=n-1; ind>=0; ind--){
//             for(int prev=ind-1; prev>=-1; prev--){
//                 //notPick- pick
//                 int notPick = 0+ dp[ind+1][prev+1];
//                 int pick = 0;
//                 if(prev==-1 || nums[ind]> nums[prev])
//                     pick = 1+dp[ind+1][ind+1];

//                 //max out of it 
//                 dp[ind][prev+1] = max(notPick, pick); 
//             }
//         }
        
//         return dp[0][0];
//     }
// };

//4. Tabulation(space- optimized): using next(n+1, 0) and curr(n+1, 0)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         //dp[n+1][n+1]: 1- based index to deal with prev = -1;
//         vector<int> next(n+1, 0), curr(n+1, 0);
        
//         //put next as dp[ind+1]
//         for(int ind=n-1; ind>=0; ind--){
//             for(int prev=ind-1; prev>=-1; prev--){
//                 //notPick- pick
//                 int notPick = 0+ next[prev+1];
//                 int pick = 0;
//                 if(prev==-1 || nums[ind]> nums[prev])
//                     pick = 1+next[ind+1];

//                 //max out of it 
//                 curr[prev+1] = max(notPick, pick); 
//             }
//             next = curr;
//         }
        
//         return curr[0];
//     }
// };


//5. O(N^2) algorithm to find LIS: check previous element of i to find the LIS[i]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> LIS(n, 1);  //LIS of len= 1, single element itself
        int mx = 1;
        //find if any of the previous element can be part of increasing sequence for the current element
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]< nums[i]){
                    LIS[i] = max(LIS[i], 1+LIS[j]);
                    mx = max(mx, LIS[i]);
                }
                    
            }
        }
        
        return mx;
    }
};


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> LIS(n, 1);  //LIS of len= 1, single element itself
//         int mx = 1;
//         //find if any of the previous element can be part of increasing sequence for the current element
//         for(int i=0; i<n; i++){
//             for(int j=0; j<i; j++){
//                 if(nums[j]< nums[i]){
//                     LIS[i] = max(LIS[i], 1+LIS[j]);
//                     mx = max(mx, LIS[i]);
//                 }
                    
//             }
//         }
        
//         //printing LIS: backtrack from the highest value of LIS
//         vector<int> hash(n);        //take care of prev index of LIS[i]
//         int ind;
        
//         //get index for LIS value
//         for(int i=0; i<n; i++){
//             if(LIS[i]==mx){
//                 ind = i;
//                 break;
//             }
//         }
      
        
        
//         return mx;
//     }
// };