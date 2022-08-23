//variation of LCS: first string will be given string and another will be the reverse of it. If any sequence is palindromic than it will definitely be longest common subseq btw those two strins.

class Solution {
public:
     int lcs(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //dp table: 0 to n1-1 --> 1 to n1 so that 0 --> -1
        vector<int> curr(n2+1, 0), prev(n2+1, 0);
        
        //base case: shift indexes to right -1 -> 0
        for(int ind2=0; ind2<=n2; ind2++) prev[ind2] = 0;
        
        //form table: ind1-> 1 to n1 & ind2-> 1 to n2
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
            //matching- not matching
            if(text1[ind1-1]== text2[ind2-1])   //do ind-1 in both string to match chars
                curr[ind2] = 1+ prev[ind2-1];
        
        else
            curr[ind2] = max(prev[ind2], curr[ind2-1]);
            
            }
            prev = curr;
        }
        
        return curr[n2];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};