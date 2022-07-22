class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        
        //push (element, index) in pq
        for(int i=0; i<score.size(); i++){
            pq.push({score[i], i});
        }
        
        vector<string> ans(score.size());
        int cnt = 1;
        while(!pq.empty()){
            auto maxx = pq.top(); pq.pop();
            int element = maxx.first;
            int index = maxx.second;
            if(cnt==1)
                ans[index] = "Gold Medal";
            else if(cnt==2)
                ans[index] = "Silver Medal";
            else if(cnt==3)
                ans[index] = "Bronze Medal";
            else
                ans[index] = to_string(cnt);
            cnt++;
        }
        
        return ans;
    }
};