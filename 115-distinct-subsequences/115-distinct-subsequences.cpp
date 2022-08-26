//recursion
// class Solution {
// public:
//     int f(int i, int j, string &s, string &t){
//         if(j<0)         //we have matched all char in t
//             return 1;
//         if(i<0)         //there is nothing to match with now in s
//             return 0;
        
//         //i matches with j: 2 possibilities whether to take i or not
//         if(s[i]==t[j])
//             return f(i-1, j-1, s, t) + f(i-1, j, s, t);
        
//         //if its not matching, you definitely have to search inside in s1 for jth char 
//         else
//             return f(i-1, j, s, t);
//     }
    
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
    
//         return f(n-1, m-1, s, t);
//     }
// };


//DP memoization: use dp array to avoid overlapping subproblems
// class Solution {
// public:
//     int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
//         if(j<0)         //we have matched all char in t
//             return 1;
//         if(i<0)         //there is nothing to match with now in s
//             return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         //i matches with j: 2 possibilities whether to take i or not
//         if(s[i]==t[j])
//             return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
//         //if its not matching, you definitely have to search inside in s1 for jth char 
//         else
//             return dp[i][j] = f(i-1, j, s, t, dp);
//     }
    
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
        
//         vector<vector<int>> dp(n, vector<int> (m, -1));
//         return f(n-1, m-1, s, t, dp);
//     }
// };


//DP tabulation: make the dp table from bottom to up
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
        
//         //shifting of index to right to utilize the base case to make the table
//         vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        
//         //use base cases to build the base of the table: -1 -> 0
//         for(int j=0; j<=m; j++) //when s exhauseted; nothing to match with t str
//             dp[0][j] = 0;
//         for(int i=0; i<=n; i++)  //when t exhausted; everyything matched
//             dp[i][0] = 1;

//         //form table i= 1 to n & j= 1 to m
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 //i matches with j: 2 possibilities whether to take i or not
//                 if(s[i-1]==t[j-1])
//                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        
//                 //if its not matching, you definitely have to search inside in s1 for jth char      
//                 else
//                     dp[i][j] = dp[i-1][j];
//             }
//         }
        
//         return (int)dp[n][m];
//     }
// };

//DP tabulation: space optimization with 1d array (to store previous row i-1 things)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        //shifting of index to right to utilize the base case to make the table
        vector<double> prev(m+1, 0), curr(m+1, 0);
        
        //put 1 for the j=0 because t is exhausted here
        prev[0] = curr[0] = 1;

        //form table i= 1 to n & j= 1 to m
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //i matches with j: 2 possibilities whether to take i or not
                if(s[i-1]==t[j-1])
                    curr[j] = prev[j-1] + prev[j];
        
                //if its not matching, you definitely have to search inside in s1 for jth char      
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        
        return (int)curr[m];
    }
};