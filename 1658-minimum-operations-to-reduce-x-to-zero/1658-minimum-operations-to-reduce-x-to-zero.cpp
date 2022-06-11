class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //x is a value which will be substracted from left and right side of the array, and this x value should be extrcated using minimum number of elements in nums. After removing x value from the left and right side, a subarray will be left in the middle having targetSum = totalSum - x;  //11-5 =6
    
        //so our task is to find this largest subarray with having sum = 6 because we need minimum elements to make value x;
        
        //step-1: Find targetSum = totalSum - x;
        // nums = 1 1 4 2 3, x= 5 
        int totalSum = 0;
        for(auto it: nums)
            totalSum += it; //11
        
        int targetSum = totalSum - x;   //11-5 = 6
        
        
        //step-2: Find largest subarray having targetSum //6
        
        //make prefix sum array of nums
        //store index of each prefix sum value
        vector<int> prefixSum;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            prefixSum.push_back(sum);
            mpp[prefixSum[i]] = i;
        }
                    
        //prefixSum = 1 2 6 8 11
        //            0 1 2 3 4
        
        //iterate in prefixSum vector from the back using j pointer. to find targetSum will use mpp
        //prefixSum[j] - targetSum = i; //8-6 = 2;
        //now find this i value in map
        int len = -1;
        for(int j= prefixSum.size()-1; j>=0; j--){
            if(mpp.find(prefixSum[j] - targetSum) != mpp.end()){  //mpp[8- 6] = mpp[2] exist in map
                len = max(len, mpp[prefixSum[j]] - mpp[prefixSum[j]- targetSum]);    //mpp[8]- mpp[2] = 3-1 = 2
                cout<< nums[j]<<endl;
            }
        }
        
        //elements selected for x= total elements - elementd used for subarray(having maximum length with targetSum)
        if(len != -1)
            return nums.size()-len;
        return -1;
    }
};