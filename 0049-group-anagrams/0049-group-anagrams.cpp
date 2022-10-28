class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //make a pair(string, ind)
        vector<pair<string, int>> strss;
        for(int i=0; i<strs.size(); i++){
            strss.push_back({strs[i], i});
        }
        
        //sort the strings so anagrams will be appear same
        for(int i=0; i<strss.size(); i++){
            sort(strss[i].first.begin(), strss[i].first.end());
        }
        
        //group same words in vector<string>
        vector<vector<string>> res;
        for(int i=0; i<strss.size(); i++){
            vector<string> temp;
            for(int j=i; j<strss.size(); j++){
                if(strss[i].first == strss[j].first){
                    if(strss[j].second == -1) continue;     //already taken
                    
                    temp.push_back(strs[strss[j].second]);
                    strss[j].second = -1;
                } 
            }
            
            if(temp.size()<=0) continue;
            res.push_back(temp);
        }
        
        return res;
    }
};