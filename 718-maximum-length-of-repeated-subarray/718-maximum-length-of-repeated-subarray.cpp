class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
	    int n1 = text1.size();
        int n2 = text2.size();
        //dp table: 0 to n1-1 --> 1 to n1 so that 0 --> -1
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        //base case: shift indexes to right -1 -> 0
        for(int ind1=0; ind1<=n1; ind1++) dp[ind1][0] = 0;
        for(int ind2=0; ind2<=n2; ind2++) dp[0][ind2] = 0;
        
        //form table: ind1-> 1 to n1 & ind2-> 1 to n2
        int ans = 0;
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
            //matching: add 1 to the prev matching substring  
            if(text1[ind1-1]== text2[ind2-1]){
                dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
                ans = max(ans, dp[ind1][ind2]);
            }   
               
            //not-matching
            else
                dp[ind1][ind2] = 0;
            
            }
        }
        
        return ans;
    }
};