//suffix sum: <-right
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        //suffix sum
        long long left=0, right = 0;
        for(int i=n-1; i>=0; i--){
            right += nums[i];
        }
        
        //get the difference and store the min index for min diff
        int diff= INT_MAX, mn = INT_MAX;
        for(int i=0; i<n; i++){
            left += nums[i];
            right -= nums[i];
          
            int temp = (n-i-1==0) ? left/n: abs(left/(i+1)- right/(n-i-1));
            if(temp< diff){
                diff= temp;
                mn = i;
            }
        }
        
        return mn;
    }
};