class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        //sort it
        sort(nums.begin(), nums.end());
        
        //prefix sum
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            nums[i] = sum;
        }
        
        
        int m = queries.size();
        vector<int> ans(m, 0);
        int j = 0;
        while(j<m){
            int i =0;
            while(i<nums.size() && nums[i]<=queries[j] && i+1> ans[j]){
                ans[j] = i+1;
                i++;
            }
                
            j++;
        }
        
        
        return ans;
    }
};