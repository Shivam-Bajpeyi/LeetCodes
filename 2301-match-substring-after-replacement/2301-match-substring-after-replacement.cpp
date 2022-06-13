class Solution {
public:
    unordered_map<char, unordered_set<int>> mpp;
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        //map mappings in map
        for(auto it: mappings)
            mpp[it[0]].insert(it[1]);
        
        //takeout every sliding window of s (of size = sub.size()) and match it with sub using map
        for(int i=0; i<=(s.size()- sub.size()); i++){
            if(match(s.substr(i, sub.size()), sub))
                return true; //if it matches
        }
        
        return false; //if any of the sliding window of s doesn't match with sub
    }
    
    bool match(string s, string sub){
        for(int i=0; i<sub.size(); i++){
            if(s[i] == sub[i] || mpp[sub[i]].count(s[i])) continue; 
            return false;
        }//check if s[i] matches with sub[i] or any element stored in mpp[s[i]] 
        
        return true;
    }
};