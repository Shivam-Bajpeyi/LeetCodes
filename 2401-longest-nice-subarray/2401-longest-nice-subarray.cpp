class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //sliding window approach, include number by taking AND & exclude someone by taking XOR
        int num = nums[0];
        int j = 0;  //use j to remove someone
        int maxi = 1;
        
        int n = nums.size();
        for(int i=1; i<n; i++){
            //make right window 
            while((num & nums[i]) !=0){
                num ^= nums[j++];
            }
            
            num |= nums[i];
            maxi = max(maxi, i-j+1);
        }
        
        return maxi;
    }
};