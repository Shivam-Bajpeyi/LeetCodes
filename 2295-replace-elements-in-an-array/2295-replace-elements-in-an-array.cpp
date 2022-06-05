class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mpp;    //store index of nums array elements 
        
        //hash nums
        for(int i=0; i<nums.size(); i++)
            mpp[nums[i]] = i;
        
        //start operations
        for(auto it: operations){
            int a = it[0];
            int b = it[1];
            
            //we have to change a->b
            nums[mpp[a]] = b;   //go to index of a in nums and store b there
            mpp[b] = mpp[a];    //index of this element will be same as previously stored element
        }
        
        return nums;
    }
};