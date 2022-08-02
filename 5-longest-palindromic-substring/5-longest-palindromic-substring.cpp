//using dp: use previosuly computed palindromes to compute new one
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        //fill 1 size & 2 size substring
        for(int i=0; i<n; i++){
            dp[i][i] = 1;   //single letter is palindrome
            if(i!= n-1 && s[i]==s[i+1])
                dp[i][i+1] = 1;
        }
        
        //remaining entries 2>= size, check first and last directly and middle subsstr with dp[][]
        for(int i=n-3; i>=0; i--){
            for(int j=i+2; j<n; j++){
                if(s[i]==s[j] && dp[i+1][j-1]==1)
                    dp[i][j] =1;

            }
        }
        
        //take out max len palindrome
        int len = INT_MIN;
        string ans = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]==1 && (j-i+1)> len){
                    len = j-i+1;
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        
        return ans;
    }
};