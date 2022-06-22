class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<int> current = intervals[0];   //will carry current interval
        vector<vector<int>> ans;
        
        
        
        //start merging
        for(int i=1; i<intervals.size(); i++){
            //merge next interval to it
            if(current[1] >= intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            }
                
            
            //push interval to ans and assign a new current
            if(current[1] < intervals[i][0]){
                ans.push_back(current);
                current = intervals[i];
            }
        }
        
        //push last interval
        ans.push_back(current);
        return ans;
    }
};