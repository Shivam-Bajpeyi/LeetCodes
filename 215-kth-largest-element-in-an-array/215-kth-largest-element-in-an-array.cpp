class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int i= nums.size()-1; i>=0; i--){
            count++;
            if(count==k)
                return nums[i];
        }
        return -1;
    }
};