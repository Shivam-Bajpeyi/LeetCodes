class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];
        
        for(auto it: nums){
           if(count==0)    //whenever count becomes 0, pick up a new element
                element = it;
            
            //keep a counter
            if(element == it)  
                count++;
            else
                count--; 
        }
            
        return element;
    
    }
};