class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        //move slow by 1 step & fast by 2 step until they meet somewhere
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
                
            if(slow== fast)
                break;
        }
        
        //now place any pointer to nums[0] and move both by 1 step to know repeating number
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};