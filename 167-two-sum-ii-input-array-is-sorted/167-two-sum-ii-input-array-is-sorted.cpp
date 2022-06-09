class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //2 pointer approach
        int start = 0;
        int end = nums.size()-1;
        
        //find 2 indexes
        vector<int> ans;
        while(start < end){
            if(nums[start]+ nums[end] == target){   //found the numbers, store them (1- index vector)
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            
            else if(nums[start]+ nums[end] < target)    //since array is sorted, moving start pointer ahead will increase sum
                start++;
            else    //if total sum is more than target, call end pointerbackward so that value obtain can be decreased
                end--;
        }
        
        return ans;
    }
};