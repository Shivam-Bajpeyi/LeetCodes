class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        long long cnt= 0, n= nums.size();
        long long mod = 1e9+7;
        
        for(int i=0; i<n; i++){
            long long temp= nums[i];
            for(int j=i; j<n; j++){
                temp= lcm(temp, 
                          nums[j])%mod;
                if(temp==k)
                    cnt++;
                else if(temp>k)
                    break;
            }
        }
        
        return cnt;
    }
};