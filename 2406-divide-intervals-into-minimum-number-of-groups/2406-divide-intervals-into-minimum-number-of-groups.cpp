class Solution {
public:
    //same as Minimum number of platforms required
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> s(n), e(n);
        
        //store arrival and departure time
        for(int i=0; i<n; i++){
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }
        
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        int res = 1;
        int cnt = 1;
        int i=1, j=0;
        
        while(i<n && j<n){
            if(s[i]<= e[j]){    //platform is occupied, need one more
                cnt++;
                i++;
            }
            else{   //any platform got empty
                cnt--;
                j++;
            }
            
            res = max(res, cnt);
        }
        
        return res;
    }
};