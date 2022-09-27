// 1. recursion
// class Solution {
// public:
//     int n;
    
//     bool isPalindrome(int i, int j, string &s){
//         while(i<j){
//             if(s[i++] != s[j--])
//                 return false;
//         }
//         return true;
//     }
    
//     long minPartition(int i, string s){
//         if(i>=n-1) return 0;    
        
//         //explore- what all the possibilities of doing partition
//         long mn = INT_MAX;
//         for(int j=i; j<n; j++){
//             if(isPalindrome(i, j, s)){
//                 long partition= 0;
//                 if(j!=n-1)
//                     partition = 1+ minPartition(j+1, s);
                
//                 mn = min(mn, partition);
//             }
//         }
        
//         return mn;      //min partitions
//     }
    
//     int minCut(string s) {
//         n = s.size();
//         return minPartition(0, s);
//     }
// };


//2. Memoization
// class Solution {
// public:
//     int n;
    
//     bool isPalindrome(int i, int j, string &s){
//         while(i<j){
//             if(s[i++] != s[j--])
//                 return false;
//         }
//         return true;
//     }
    
//     long minPartition(int i, string s, vector<int> &dp){
//         if(i>=n-1) return 0;    
        
//         if(dp[i] !=-1) return dp[i];
        
//         //explore- what all the possibilities of doing partition
//         long mn = INT_MAX;
//         for(int j=i; j<n; j++){
//             if(isPalindrome(i, j, s)){
//                 long partition= 0;
//                 if(j!=n-1)
//                     partition = 1+ minPartition(j+1, s, dp);
                
//                 mn = min(mn, partition);
//             }
//         }
        
//         return dp[i]= mn;      //min partitions
//     }
    
//     int minCut(string s) {
//         n = s.size();
//         //dp
//         vector<int> dp(n+1, -1);
//         return minPartition(0, s, dp);
//     }
// };

//3. Tabulation
class Solution {
public:
    int n;
    
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    
    int minCut(string s) {
        n = s.size();
        //dp
        vector<int> dp(n, 0);
        
        //explore- what all the possibilities of doing partition
        for(int i=n-2; i>=0; i--){
            long mn = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    long partition= 0;
                    if(j!=n-1)
                        partition = 1+ dp[j+1];

                    mn = min(mn, partition);
                }
            }    
            dp[i]= mn;      //min partitions
        }
        
        return dp[0];
    }
};