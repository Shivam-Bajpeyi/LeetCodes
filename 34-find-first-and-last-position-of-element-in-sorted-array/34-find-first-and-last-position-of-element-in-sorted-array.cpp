class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        
        
        //step-1: Binary search to find target in nums
        int start= 0, end = n-1;
        int idx = -1;   //index where target found
        while(start <= end){
            if(nums[0]==target){
                idx = 0;
                break;
            }
                
            int mid = (start+end)/2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }
                
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        
        if(idx==-1)
            return res;     //return [-1, -1] if target is not in nums
        
    
        //step-2: find first and last index by using idx of target found in nums
        start = idx, end = idx; //point both pointer at idx 
        
        //start searching in all the way left & right to find the first and last occurence
        while(nums[start] == target && start>=0){
            if(start-1 >= 0  && nums[start-1]==target)
                start--;
            else
                break;
        }
            
        while(nums[end]==target && end<n){
            if(end+1 <n && nums[end+1]==target)
                end++;
            else
                break;
        }
            
        
        res[0] = start, res[1] = end;
        return res;
            
     }
};