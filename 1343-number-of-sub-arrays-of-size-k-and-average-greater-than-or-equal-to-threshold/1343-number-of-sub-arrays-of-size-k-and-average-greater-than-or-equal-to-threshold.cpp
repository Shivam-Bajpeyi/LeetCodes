class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        //sliding window
        int i=0, j=0, sum = 0, n= nums.size();
        
        //fit the window to make it size k
        while(i-j+1 < k){
            sum+= nums[i++];
        }
        
        int cnt = 0;
        for(int i=k-1; i<n; i++){
            sum+= nums[i];
            
            //fit the window
            if(i-j+1 > k)
                sum -= nums[j++];
            
            //take avg of k window, if avg>= thresold count it
            if(i-j+1 ==k && sum/k>=threshold)
                cnt++;
        }
        
        return cnt;
    }
};