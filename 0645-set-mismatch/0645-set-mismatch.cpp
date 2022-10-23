class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int num = 0;
        sort(nums.begin(), nums.end());
        set<int> st;
        for(int it: nums)
            st.insert(it);
        
        int dup= -1, missing = -1;
        for(int i=1; i<=nums.size(); i++){
            if(!st.count(i)){
                missing = i;
                break;
            }
                
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) dup = nums[i];
        }
        
        return {dup, missing};
    }
};