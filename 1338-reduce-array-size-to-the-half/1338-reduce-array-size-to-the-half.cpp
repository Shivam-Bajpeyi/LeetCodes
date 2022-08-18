class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        //count frequency
        unordered_map<int, int> mpp;
        for(auto &it: arr)
            mpp[it]++;
        
        //priority_queue: push freq of the elements to pq
        priority_queue<int> pq;
        for(auto &it: mpp)
            pq.push(it.second);

        //take out frequencies till total freq>=n/2
        int count = 0;
        int ans = 0;
        while(!pq.empty() && count < n/2){
            count += pq.top(); pq.pop();
            ++ans;  //how many elements set has made
        }
        
        return ans;
    }
};