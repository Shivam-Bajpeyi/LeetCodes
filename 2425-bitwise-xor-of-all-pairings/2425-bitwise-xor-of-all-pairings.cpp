class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int val1 = nums1[0], val2 = nums2[0];
        //xor1
        for(int i=1; i<n1; i++){
            val1 = (val1^nums1[i]);
        }
        
        //num2 size times multiply
        int temp1 = val1;
        for(int i=1; i<n2; i++)
            temp1= (temp1^val1);
        
        //xor2
        for(int j=1; j<n2; j++){
            val2 = (val2^nums2[j]);
        }
        
        int temp2 = val2;
        //num1 size times multiply
        for(int j=1; j<n1; j++)
            temp2= (temp2^val2);
        
        
        return (temp1^temp2);
    }
};