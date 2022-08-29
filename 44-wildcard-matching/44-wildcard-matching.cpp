//considering s => contains lowercase + '?' + '*'
//            p => contains only lowercase


//1. recursion
// class Solution {
// public:
//     bool f(int i, int j, string &s, string &p){
//         if(i<0 && j<0) return true;     //both have matched
//         if(i<0 && j>=0) return false;   //not gonna match
//         if(j<0 && i>=0){   //if s2 is exhausted, s1 should have only '*'
//             for(int ii=0; ii<=i; ii++){
//                 if(s[ii] != '*') return false;
//             }
//             return true;
//         }
        
//         //match- '?' will match to the jth char
//         if(s[i] == p[j] || s[i]=='?') return f(i-1, j-1, s, p);
        
//         //if s[i] is astric, try matching by assuming '*' can match with any sequemce in str2 0 to remaining part
//         if(s[i]== '*')
//             return f(i-1, j, s, p) || f(i, j-1, s, p);
//             //assign * nothing || assume it will match with j-1 
        
//         //other than above conditions
//         return false;
//     }
    
//     bool isMatch(string p, string s) {
//         int n = s.size();
//         int m = p.size();   //contains lowercase + '?' + '*'
        
        
//         return f(n-1, m-1, s, p);
//     }
// };

//2. DP memoization: avoid solving already solved sub-problems
// class Solution {
// public:
//     bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
//         if(i<0 && j<0) return true;     //both have matched
//         if(i<0 && j>=0) return false;   //not gonna match
//         if(j<0 && i>=0){   //if s2 is exhausted, s1 should have only '*'
//             for(int ii=0; ii<=i; ii++){
//                 if(s[ii] != '*') return false;
//             }
//             return true;
//         }
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         //match + '?' will match to the jth char
//         if(s[i] == p[j] || s[i]=='?') 
//             return dp[i][j] = f(i-1, j-1, s, p, dp);
        
//         //if s[i] is astric, try matching by assuming '*' can match with any sequemce in str2 0 to remaining part: assign * nothing || assume it will match with j-1 
//         if(s[i]== '*')
//             return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        
//         //other than above conditions
//         return false;
//     }
    
//     bool isMatch(string p, string s) {
//         int n = s.size();
//         int m = p.size();   //contains lowercase + '?' + '*'
        
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return f(n-1, m-1, s, p, dp);
//     }
// };


//3. Tabulation: build dp table(bottom->up) using base case(right shift of index) & recurrence relation
class Solution {
public:
    bool isMatch(string p, string s) {
        int n = s.size();
        int m = p.size();   //contains lowercase + '?' + '*'
        
        //right shift of index: -1 ->0 
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        
        //build base using base
        dp[0][0] = 1;   //i<0 && j<0
        for(int j=1; j<=m; j++) //i<0 && j>=0 
            dp[0][j] = 0;
        for(int i=1; i<=n; i++){    //if i>=0 && j<0
            if(s[i-1] == '*')
                dp[i][0] = 1;
            else
                break;
        }
            
        //build complete table using recurrence relation
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
            //match + '?' will match to the jth char
            if(s[i-1] == p[j-1] || s[i-1]=='?') 
                dp[i][j] = dp[i-1][j-1];

            //if s[i] is astric, try matching by assuming '*' can match with any sequemce in str2 0 to remaining part: assign * nothing || assume it will match with j-1 
            else if(s[i-1]== '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
                
            else
                dp[i][j] = 0;
            }
        }
        
        return dp[n][m];
    }
};