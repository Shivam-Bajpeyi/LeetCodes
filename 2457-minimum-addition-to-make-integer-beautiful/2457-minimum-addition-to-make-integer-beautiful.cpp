class Solution {
public:
    long long sumOfDigits(long long n){
        long long sum = 0;
        
        while(n>0){
            sum += n%10;    //digit
            n /= 10;
        }
        
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
       long long n0 = n, base = 1;
        while (sumOfDigits(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - n0;
    }
};