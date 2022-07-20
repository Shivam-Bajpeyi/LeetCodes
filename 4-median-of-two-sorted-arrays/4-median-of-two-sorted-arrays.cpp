//Brute: get indices of median elements using merge sort (tc: O(M+N), sc: O(1))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        //just get the indices while merging not literally store all elements
        int m1= (n1+n2)/2;
        int m1Element = 0;
        int m2 = (n1+n2)/2-1;
        int m2Element = 0;
        
        int i= 0, j= 0, k= 0;
        while(i<n1 && j<n2){
            if(nums1[i]<= nums2[j]){
                if(m1==k)
                    m1Element = nums1[i];
                if(m2==k)
                    m2Element = nums1[i];
                ++k;  ++i;
                
            }
                
            else{
                if(m1==k)
                    m1Element = nums2[j];
                if(m2==k)
                    m2Element = nums2[j];
                ++k; ++j; 
            }
                
        }
        
        while(i<n1){
            if(m1==k)
                m1Element = nums1[i];
            if(m2==k)
                m2Element = nums1[i];
            ++k;  ++i;
        }
        while(j<n2){
            if(m1==k)
                m1Element = nums2[j];
            if(m2==k)
                m2Element = nums2[j];
            ++k; ++j;
        }
        
        //find median now in this sorted array
        int n = n1+n2;
        if(n%2)   //odd
            return m1Element;
        else
            return (m1Element + m2Element)/2.0;
            
    }
};