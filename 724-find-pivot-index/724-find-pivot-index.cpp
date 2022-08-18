class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum  = 0;
        int total = 0;
        for(auto &it: nums)
            total += it;
        
        for(int i=0; i<nums.size(); i++){
            if(sum == total-sum-nums[i])    //if left sum == right sum
                return i;
            sum += nums[i];
        }
        
        return -1;
    }
};