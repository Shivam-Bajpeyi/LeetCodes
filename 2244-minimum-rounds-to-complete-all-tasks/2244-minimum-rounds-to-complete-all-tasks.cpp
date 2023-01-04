class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for(auto &it: tasks)
            mpp[it]++;
        
        int cnt = 0;
        for(auto &it: mpp){
            while(it.second>=2){
                cnt++;
                if(it.second%3==0)
                    it.second -= 3;
                else
                    it.second -= 2;
            }
            
            if(it.second != 0) return -1;
        }
        
        return cnt;
    }
};