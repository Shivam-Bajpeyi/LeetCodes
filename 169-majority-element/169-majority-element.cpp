class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        //count frequency of every element
        for(auto it: nums)
            freq[it]++;
        
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] > n/2)
                return nums[i];
        }
        
        return -1;
        
    }
};