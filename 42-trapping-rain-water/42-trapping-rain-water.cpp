//Efficient: make prefix and suffix array to find leftmax and rightmax quickly
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size(), waterStored = 0;
        vector<int> leftmax(n), rightmax(n);
        
        //leftmax
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(height[i]>maxi)
                maxi = height[i];
            leftmax[i] = maxi;
        }
           
        //rightmax
        maxi =0;
        for(int i=n-1; i>=0; i--){
            if(height[i]>maxi)
                maxi = height[i];
            rightmax[i] = maxi;
        }
            
            
        //find waterStored for every block
        for(int i=0; i<n; i++){
            int leftmaxi = leftmax[i];
            int rightmaxi = rightmax[i];
            
            waterStored += min(leftmaxi, rightmaxi) - height[i];
        }
        
        return waterStored;
    }
};