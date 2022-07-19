class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        
        while(low<=high){
            int mid = (low+high)>>1;
            
            if(mid%2== 0){ //digit is even
                //if it is right part, next odd index will not be same
                if(nums[mid] != nums[mid+1])
                    high = mid-1;   //move towards break point
                else    //left subarray
                    low = mid+1;
            }
            
            else{   //if digit is odd
                //if it is right part, it's even will be same
                if(nums[mid]== nums[mid+1])
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        
        return nums[low];
    }
};