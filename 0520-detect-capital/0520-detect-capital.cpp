class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        int capital = 0;
        for(int i=0; i<n; i++){
            if(word[i]<=90) capital++;
        }
        
        //all capital or all small
        if(capital==0 || capital==n) return true;
        else if(capital==1 && word[0]<=90) return true;
        return false;
    }
};