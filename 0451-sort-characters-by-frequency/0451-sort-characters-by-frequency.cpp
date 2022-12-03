//hashmap + heap
class Solution {
public:
    string frequencySort(string s) {
        //hashmap to store freq of the char
        unordered_map<char, int> mpp;
        for(auto &it: s){
            mpp[it]++;
        }
        
        //heap to store bigger freq
        priority_queue<pair<int, char>> pq;
        for(auto &it: mpp){
            pq.push({it.second, it.first});         //(2, e)
        }
        
        //extract
        string ans = "";
        while(!pq.empty()){
            auto topp = pq.top();
            pq.pop();
            char ch = topp.second;
            int cnt = topp.first;
            string s(cnt, ch);
            ans += s; 
        }
        
        return ans;
    }
};