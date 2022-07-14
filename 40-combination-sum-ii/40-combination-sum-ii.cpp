class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        f(n-1, 0, target, candidates, temp, ans);
        return ans;
    }
    
    void f(int ind, int pre, int target, vector<int>& candidates, vector<int> temp, vector<vector<int>> &ans){
        if(ind<0 || target==0){   
            if(target== 0)
                ans.push_back(temp);
            return;
        }
        
         //not- pick
        f(ind-1, target, target, candidates, temp, ans);
        
        //avoid duplicate
        if(ind< candidates.size()-1 && candidates[ind]==candidates[ind+1] && pre==target) return;
        
        //pick 
        if(candidates[ind]<= target){
            temp.push_back(candidates[ind]);
            f(ind-1, target, target-candidates[ind], candidates, temp, ans);
            temp.pop_back();
        }
        
       
    }
};