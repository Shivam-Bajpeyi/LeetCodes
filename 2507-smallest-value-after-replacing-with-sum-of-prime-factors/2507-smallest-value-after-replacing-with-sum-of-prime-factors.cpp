class Solution {
public:
    int sumOfPrimeFactrs(int n){
        //divisor starting from 2, so everytime divisor will be prime factors only
        int divisor = 2;
        int sum = 0;
        while(n>1){
            if(n%divisor == 0){
                sum += divisor;
                n = n/divisor;
            }
                
            else
                divisor++;
        }
        
        return sum;
    }
    
    int smallestValue(int n) {
        while(1){
            int sum = sumOfPrimeFactrs(n);
            if(sum == n) return n;
            n = sum;
        }
        
        return -1;
    }
};