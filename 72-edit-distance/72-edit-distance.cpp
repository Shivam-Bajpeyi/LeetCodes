//1. recursion: match and not-match(take min of 3 operations insert, delete, and replace)
// class Solution {
// public:
//     int f(int i, int j, string &word1, string &word2){
//         if(i<0) return j+1; //insert j+1 characters to make s1 -> s2
//         if(j<0) return i+1; //delete i+1 characters to make s1 -> s2
        
//         //matching- not matching
//         if(word1[i] == word2[j]) return 0 + f(i-1, j-1, word1, word2);
//         else
//             return 1 + min(f(i, j-1, word1, word2), min(f(i-1, j, word1, word2), f(i-1, j-1, word1, word2)));
//             //whatever gives min among insert, delete, and replace
//     }
    
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
        
//         return f(n-1, m-1, word1, word2);
//     }
// };


//2. DP memoization: to avoid solving overlapping sub-problems
class Solution {
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i<0) return j+1; //insert j+1 characters to make s1 -> s2
        if(j<0) return i+1; //delete i+1 characters to make s1 -> s2
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //matching- not matching
        if(word1[i] == word2[j]) return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);
        else
            return dp[i][j] = 1 + min(f(i, j-1, word1, word2, dp), min(f(i-1, j, word1, word2, dp), f(i-1, j-1, word1, word2, dp)));
            //whatever gives min among insert, delete, and replace
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return f(n-1, m-1, word1, word2, dp);
    }
};