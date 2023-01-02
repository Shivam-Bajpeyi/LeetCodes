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
        
        int cnt2= 0;
        //count the freq of letters in t
        unordered_map<char, int> mpp2;
        for(auto &it: t){
            mpp2[it]++;
        }
        
        //min steps = how many diff letters do s string have, that we need to replace
        for(auto &it: s){
            if(mpp2[it]>0){
                mpp2[it]--;
            }
            else
                cnt2++;
        }
        
        return cnt+cnt2;
    }
};