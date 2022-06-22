class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        //step-1 find ind1 from backward such that nums[i] < nums[i+1]
        int ind1 = 0;
        for(ind1=n-2; ind1>=0; ind1--)
            if(nums[ind1] < nums[ind1+1])
                break;
        
        //last permutation is given (3 2 1) return (1 2 3)
        if(ind1< 0)
            reverse(nums.begin(), nums.end());
        
        else{
            //step-2 find ind2 from end till ind1 such that nums[i] > nums[ind1] 
        int ind2 = 0;
        for(int i=n-1; i>=ind1; i--){
            if(nums[i] > nums[ind1]){
                ind2= i;
                break;
            }
                
        }
        
        //step-3 swap (ind1, ind2) & reverse array from ind1+1 to end
        swap(nums[ind1], nums[ind2]);
        reverse(nums.begin()+ind1+1, nums.end());
        }
        
    }
};