//store all the strings(anagram) corresponds to a sorted word and store all of them 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        //store
        for(string s: strs){
            string t= s;
            sort(t.begin(), t.end());
            mpp[t].push_back(s);            //aet = "eat", "tea", "ate"
        }
        
        //store in ans
        vector<vector<string>> res;
        for(auto &it: mpp){
            res.push_back(it.second);
        }
        
        return res;
    }
};