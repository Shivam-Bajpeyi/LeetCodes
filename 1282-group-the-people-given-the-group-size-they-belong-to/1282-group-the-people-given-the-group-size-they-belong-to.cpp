class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mpp;
        
        //3 -> (0, 1, 2)
        //push indices that belong to group size nums[i]
        for(int i=0; i<gSizes.size(); i++){
            //if the members are less than capacity of the grp
            if(mpp[gSizes[i]].size() < gSizes[i])
                mpp[gSizes[i]].push_back(i);
            
            //if the grp is full push the members in ans
            if(mpp[gSizes[i]].size() == gSizes[i]){
                res.push_back(mpp[gSizes[i]]);  //push the elements vector
                mpp[gSizes[i]].clear();
            }  
        }
        
        return res;
    }
};