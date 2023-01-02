class Solution {
public:
    string customSortString(string order, string s) {
        //hash string s
        unordered_map<char, int> mpp;   
        for(auto &it: s){
            mpp[it]++;
        }
       
        //make ans
        string ans = "";
        for(auto &it: order){
            ans += string(mpp[it], it);
            mpp[it] = 0;
        }
        
        for(auto &it: mpp){
            ans += string(it.second, it.first);
        }
        
        return ans;
    }
};