class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int AR) {
        int n = capacity.size();
        vector<int> nums;
        for(int i=0; i<n; i++){
            nums.push_back(capacity[i]-rocks[i]);
        }
        
        //sort it
        sort(nums.begin(), nums.end());
        
        int i= 0;
        while(i<n && AR>=nums[i]){
            AR -= nums[i];
            i++;
        }
        
        return i;
    }
};