class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        //count frequency of nums1 elements
        for(int i=0; i<nums1.size(); i++)
            mpp[nums1[i]]++;
        
        //find if nums2 element present in nums1 using map
        //if matched=> then we will decrease its frequency by 1
            for(int i=0; i<nums2.size(); i++){
                if(mpp[nums2[i]] > 0){    //element's frequency should not be 0
                    ans.push_back(nums2[i]);
                    mpp[nums2[i]]--;    //decrease frequency
                }     
            }
        
        return ans;
    }
};