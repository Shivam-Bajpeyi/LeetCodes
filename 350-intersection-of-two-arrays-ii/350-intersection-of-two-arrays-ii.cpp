class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        //count frequency of nums2 elements
        for(int i=0; i<nums2.size(); i++)
            mpp[nums2[i]]++;
        
        //take element one by one from nums1 and start matching to nums2's elements
        //if matched=> nums1[i] == nums2[j] then we will decrease its frequency by 1
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j] && mpp[nums2[j]]!= 0){    //element's frequency should not be 0
                    ans.push_back(nums1[i]);
                    mpp[nums2[j]]--;    //decrease frequency
                    break;
                }
                    
            }
        }
        
        return ans;
    }
};