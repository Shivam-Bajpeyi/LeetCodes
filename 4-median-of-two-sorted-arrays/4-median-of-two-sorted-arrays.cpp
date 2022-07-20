//Brute: merge sort (tc: O(M+N), sc: O(M+N))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //merge arrays
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums(n1+n2);    //to store merged array
        
        //merge arrays
        int i= 0, j= 0, k= 0;
        while(i<n1 && j<n2){
            if(nums1[i]<= nums2[j])
                nums[k++] = nums1[i++];
            else
                nums[k++] = nums2[j++];
        }
        
        while(i<n1)
            nums[k++] = nums1[i++];
        while(j<n2)
            nums[k++] = nums2[j++];
        
        //find median now in this sorted array
        int n = n1+n2;
        if(n%2)   //odd
            return nums[n/2];
        else
            return (nums[n/2-1]+ nums[n/2])/2.0;
            
    }
};