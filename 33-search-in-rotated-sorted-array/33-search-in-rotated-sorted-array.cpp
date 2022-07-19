//Binary seach: after calculating mid, any of the part left/right will be sorted then check in that sorted part where will target exist. 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<= high){
            int mid = (low+ high)>>1;
            
            if(nums[mid]== target)
                return mid;
            
            //check in sorted part left/right, in which part target may exist
            else if(nums[low] <= nums[mid]){    //left sorted part
                if(nums[low]<= target && target<= nums[mid])
                    high = mid-1;   
                else
                    low = mid+1;
            }
               
            else{   //right part is sorted
                if(nums[mid]<= target && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
                
        }
        
        return -1;
    }
};