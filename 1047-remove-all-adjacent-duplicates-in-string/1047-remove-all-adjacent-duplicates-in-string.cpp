class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        
        for(int i=0; i<s.size(); i++){
            res.push_back(s[i]);
            
            //remove adjacent duplicate letters
            while(res.size() && i<s.size() && res.back()==s[i+1]){
                res.pop_back();
                i++;
            }    
        }
        
        return res;
    }
};