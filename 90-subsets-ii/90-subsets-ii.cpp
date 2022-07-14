class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        f(nums.size()-1, temp, ans, nums);
        return ans;
    }
    
     void f(int ind, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums){
        
        if(ind<0){
            if(find(ans.begin(), ans.end(), temp) == ans.end())
                ans.push_back(temp);
            return;
        }
            
        //pick
        temp.push_back(nums[ind]);
        f(ind-1, temp, ans, nums);
         
        //not pick
        temp.pop_back();
        f(ind-1, temp, ans, nums);
    }
};