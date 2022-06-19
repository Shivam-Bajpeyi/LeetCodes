class Solution {
public:
    int longestSubsequence(string s, int k) {
        int mxLen = 0;
        int n = s.size();
        
        //take all 0s to maximize length
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0')
                mxLen++;
        }
        
        //start taking 1 from the end(binary number) till sum<=k
        int sum = 0; //since we have 0s only in the subsequence
        int j= 0;
        for(int i= n-1; i>=0; i--){
            if(s[i]== '1' && j<31){
                sum += pow(2, j);
                // cout<< sum<<" ";
                if(sum <= k)
                    mxLen++;
                else
                    break;
            }
            j++;
        }
        
        return mxLen;
    }
};