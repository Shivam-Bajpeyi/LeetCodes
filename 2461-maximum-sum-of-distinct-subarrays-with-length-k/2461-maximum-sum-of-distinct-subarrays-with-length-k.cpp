class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        
        //max subarray sum
        sum = 0;
        unordered_map<int, int> st;
            
        long long mx = 0;
        for(int i=0; i<nums.size(); i++){
            if(i<=k-1){
                st[nums[i]]++;
                sum += nums[i];
            }
                
            
            else if(i>k-1){
                st[nums[i-k]]--;
                sum -= nums[i-k];
                st[nums[i]]++;
                sum += nums[i];
                
                if(st[nums[i-k]]==0)
                    st.erase(nums[i-k]);
            }
            
            // cout<<prefixSum[i]<<endl;
            if(i>=k-1 && st.size()==k && sum>mx){
                mx = sum;
            } 
        }
        
        return mx;
    }
};