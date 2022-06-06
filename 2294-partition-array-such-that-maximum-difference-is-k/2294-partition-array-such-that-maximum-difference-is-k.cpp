class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int j = 0;
        int ans = 1;    //complete array is 1 subsequence in itself
        
        //sort in decreasing fashion
        sort(nums.begin(), nums.end(), greater<int>());
        
        //if the difference between elements (nums[j]- nums[i] > k) book a new subsequence
        for(int i=1; i<nums.size(); i++){
            if(nums[j]- nums[i] > k){
                ans++;
                j = i;
            }
        }
        
        return ans;
    }
};