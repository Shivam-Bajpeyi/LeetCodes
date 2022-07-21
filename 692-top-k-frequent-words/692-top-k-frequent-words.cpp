class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        
        //store frequencies
        for(auto &it: words)
            mpp[it]++;
        
        //push frequency with element in pq(freq, string)
       priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto &it: mpp){
            pq.push({it.second, it.first});
        }
        
        //get k frequent elements
        vector<string> ans;
        while(k--){
            auto topp = pq.top();
            pq.pop();
            ans.push_back(topp.second);
        }
        
        // sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};