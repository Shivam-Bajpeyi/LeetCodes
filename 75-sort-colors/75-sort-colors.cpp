class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ind = 0;    //used to index elements for sorting
        int n = nums.size();
        
        vector<int> ans(n);
        //fix 0s from the 0th index
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                ans[ind++] = nums[i];
        }
        
        //1s
        for(int i=0; i<n; i++){
            if(nums[i] == 1)
                ans[ind++] = nums[i];
        }
        
        //2s
        for(int i=0; i<n; i++){
            if(nums[i] == 2)
                ans[ind++] = nums[i];
        }
        
        nums = ans;
    }
};