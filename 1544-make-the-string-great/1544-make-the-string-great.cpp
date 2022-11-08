class Solution {
public:
    string makeGood(string s) {
        string res;
        for(int i=0; i<s.size(); i++){
            res.push_back(s[i]);
            while(res.size() && abs(s[i+1]- res.back())==32){
                res.pop_back();
                i++;
            }
        }
        
        return res;
    }
};