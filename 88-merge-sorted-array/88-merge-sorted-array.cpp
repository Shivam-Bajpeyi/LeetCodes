class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        
        //merge sort, compare two elments at nums1[i] and nums2[j] whichever will be bigger will store that at k because we want to sort array in non- decreasing order in nums1
        while(i>=0 && j>=0){
            if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        
        //if nums1 has elements remaining
        while(i>=0)
            nums1[k--] = nums1[i--];
        
        //if nums2 has elements remaining
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};