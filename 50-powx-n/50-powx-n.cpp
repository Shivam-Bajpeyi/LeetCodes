class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        
        long long nn = n;
        if(nn<0) nn = nn*-1;
            
        while(nn>0){
            if(nn%2== 1){ //odd (2^5)
                ans = ans* x;   // 2^5 = 2 * (2^4)
                nn -= 1;    //power reduced by 1
            }
            else{
                x = (x*x);
                nn /= 2;
            }
                
        }
        
        if(n<0) return (double) 1/ (double) ans;
        return ans;
    }
};