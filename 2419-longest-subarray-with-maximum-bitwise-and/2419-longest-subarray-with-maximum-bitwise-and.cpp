//ans = how many contigious max element are there
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        int subArray = 0, ans = 1;
        for(int i=0; i<n; i++){
            if(nums[i]== mx)
                subArray++;
            else
                subArray= 0;
            
            ans= max(ans, subArray);
        }
        
        return ans;
    }
};