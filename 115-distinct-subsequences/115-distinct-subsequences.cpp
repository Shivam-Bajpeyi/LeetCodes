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
class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j<0)         //we have matched all char in t
            return 1;
        if(i<0)         //there is nothing to match with now in s
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //i matches with j: 2 possibilities whether to take i or not
        if(s[i]==t[j])
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        //if its not matching, you definitely have to search inside in s1 for jth char 
        else
            return dp[i][j] = f(i-1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};