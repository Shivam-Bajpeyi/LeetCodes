class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        
        f(n-1, target, candidates, temp, ans);
        return ans;
    }
    
    void f(int ind, int target, vector<int>& candidates, vector<int> temp, vector<vector<int>> &ans){
        if(ind<0){
            if(target== 0)
                ans.push_back(temp);
  
            return;
        }
        
        //pick (same number may be chosen unlimited number of times.)
        if(candidates[ind]<= target){
            temp.push_back(candidates[ind]);
            f(ind, target-candidates[ind], candidates, temp, ans);
            temp.pop_back();
        }
        
        //not- pick
        f(ind-1, target, candidates, temp, ans);
        
        return; //if nums[ind] > target
    }
};