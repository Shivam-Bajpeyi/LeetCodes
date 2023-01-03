class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> mark(right+1, 1);
        
        //mark prime numbers between 2 to right using sieve algo
        for(int i=2; i*i<=right; i++){
            //mark all multiple of prime number as 0
            if(mark[i]==1){
                for(int j=i*i; j<=right; j+=i){
                    mark[j] = 0;
                }
            }
        }
        
        //collect all prime in a vector in range
        vector<int> nums;
        for(int i=max(2, left); i<=right; i++){
            if(mark[i]==1)
                nums.push_back(i);
        }
        
        //take min difference between two prime numbers n1 and n2 in range 
        int n1= -1, n2 = -1, mini = INT_MAX;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]- nums[i-1]< mini){
                n1 = nums[i-1];
                n2 = nums[i];
                mini = n2-n1;
            }
        }
        
        return {n1, n2};
    }
};