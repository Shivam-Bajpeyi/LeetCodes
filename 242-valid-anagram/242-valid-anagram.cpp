class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();   //n= s.size() = t.size()
        //if any element occuring in s increase the freq and decrease the frequency for element that occurs in t
        unordered_map<char, int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        
        for(auto &it: mpp){
            if(it.second>0) //that means some letter is not occuring equal number of times in both strings
                return false;
        }
        
        return true;
           
    }
};