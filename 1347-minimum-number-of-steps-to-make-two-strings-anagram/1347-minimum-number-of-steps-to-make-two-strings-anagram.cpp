class Solution {
public:
    int minSteps(string s, string t) {
        //count the freq of letters in s
        unordered_map<char, int> mpp;
        for(auto &it: s){
            mpp[it]++;
        }
        
        //min steps = how many diff letters do t string have, that we need to replace
        int cnt= 0;
        for(auto &it: t){
            if(mpp[it]>0){
                mpp[it]--;
            }
            else
                cnt++;
        }
        
        return cnt;
    }
};