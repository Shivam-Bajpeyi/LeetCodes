class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        
        //sum even elements
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 ==0)
                sum += nums[i];
        }
        
        //take each query one by one and store answer in a vector
        vector<int> res;
        for(auto it: queries){
            if(nums[it[1]]%2 ==0)   //substract the even element from sum
                sum -= nums[it[1]];
            
            int num = nums[it[1]] + it[0];
            nums[it[1]] = num;
            
            if(num%2==0) 
                sum+= num;
            
            res.push_back(sum);
        }
        
        return res;
    }
};