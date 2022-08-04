class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size()==0)
            return prefix;
        
        //check 
        for(int i=0; i<strs[0].size(); i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[0][i] != strs[j][i])
                    return prefix;
            }
            prefix += strs[0][i];
        }
        
        return prefix;
    }
};