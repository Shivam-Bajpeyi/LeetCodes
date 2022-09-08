class Solution {
public:
  //comapre whether arr[i] can be a predecessor of arr[j]
    bool compare(string &A, string &B){
        if(A.size()+1 != B.size()) return false;
        
        //A = xb, B = xbc
        int i = 0, j = 0;
        int n1 = A.size(), n2 = B.size();
        while(j<n2){
            if(i<n1 && A[i] == B[j]){
                i++; j++;
            }   
            else
                j++;
        }
        
        if(i==n1 && j==n2)
            return true;
        return false;
    }
    
    static bool comp(string &a, string &b){
        return a.size()< b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        
        vector<int> dp(n, 1);  //LSC of len= 1, single element itself
        int mx = 1;
        
        //check if the current string has made by just inserting one elment in prev string
        for(int i=0; i<n; i++){
            cout<<words[i]<<endl;
            for(int j=0; j<i; j++){
                if(compare(words[j], words[i]) && 1+dp[j]> dp[i]){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    dp[i] =  1+dp[j];
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;    
    }
};