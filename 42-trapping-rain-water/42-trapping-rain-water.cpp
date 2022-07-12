//optimal: 2 pointer approach
class Solution {
public:
     int trap(vector<int>& height) {
        int n= height.size(), waterStored = 0;
        int l=0, r= n-1;
        int leftmax = height[l], rightmax =height[r];
        
        
        //find waterStored for every block
        while(l<=r){
            if(height[l] <= height[r]){     //leftmax bar is smaller  
                if(height[l] >= leftmax)    //update leftmax
                    leftmax = height[l];
                else
                    waterStored += leftmax- height[l];
                l++;
            }
            
            else{   //when rightmax bar is smaller
                if(height[r] >= rightmax)
                    rightmax = height[r];
                else
                    waterStored += rightmax- height[r];
                r--;
            }   
        }
        
        return waterStored;
    }
};