//1. recursion
// class Solution {
// public:
//     int n;
    
//     int f(int i, vector<int> &arr, int k){
//         if(i==n) return 0;
         
//         int sum = INT_MIN;
//         int mx = INT_MIN;
//         int len = 0;
//         //explore: do partition ind = i to i+k
//         for(int ind=i; ind<min(i+k, n); ind++){
//             len++;
//             mx = max(mx, arr[ind]);
//             int temp =  mx*len + f(ind+1, arr, k);
//             sum = max(sum, temp);
//         }
        
//         return sum;
//     }
    
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();
        
//         return f(0, arr, k);
//     }
// };

//2. Memoization dp[n]
// class Solution {
// public:
//     int n;
    
//     int f(int i, vector<int> &arr, int k, vector<int> &dp){
//         if(i==n) return 0;
         
//         if(dp[i] != -1) return dp[i];
        
//         int sum = INT_MIN;
//         int mx = INT_MIN;
//         int len = 0;
//         //explore: do partition ind = i to i+k
//         for(int ind=i; ind<min(i+k, n); ind++){
//             len++;
//             mx = max(mx, arr[ind]);
//             int temp =  mx*len + f(ind+1, arr, k, dp);
//             sum = max(sum, temp);
//         }
        
//         return dp[i] = sum;
//     }
    
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();
//         //dp[n] = 0 to n-1
//         vector<int> dp(n, -1);
//         return f(0, arr, k, dp);
//     }
// };

//tabulation dp[n] = build n-1 to 0
class Solution {
public:
    int n;
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        
        //dp[n] = 0 to n-1
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            int sum = INT_MIN;
            int mx = INT_MIN;
            int len = 0;
            //explore: do partition ind = i to i+k
            for(int ind=i; ind<min(i+k, n); ind++){
                len++;
                mx = max(mx, arr[ind]);
                int temp =  mx*len + dp[ind+1];
                sum = max(sum, temp);
            }   
            
            dp[i] = sum;
        }
        
        return dp[0];
    }
};