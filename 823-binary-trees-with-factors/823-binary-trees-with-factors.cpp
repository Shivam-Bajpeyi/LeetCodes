class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, long> mpp;
        
        //sort the array
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++)
            {
                int val = arr[i]/arr[j];
                if(arr[j]*val==arr[i] && mpp.count(val))
                {
                    mpp[arr[i]] = mpp[arr[i]] + (mpp[arr[j]] * (mpp[val]));
                }
            }
            mpp[arr[i]]++;
        }
        
        //count how many times every element can become node
        int total = 0;
        int mod = 1000000000+7;
        for(auto it: arr)
            total = (total+mpp[it])%mod;
        
        return total;
    }
};