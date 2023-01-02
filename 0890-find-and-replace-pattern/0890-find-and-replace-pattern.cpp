class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0; i<words.size(); i++){
            if(words[i].size() != pattern.size()) continue;
            else{
                unordered_map<char, char> mpp;
                set<char> st;
                for(int j=0; j<words[i].size(); j++){
                    //new char in pattern hash it to word[i][j]
                    if(mpp.find(pattern[j])== mpp.end()){
                        if(st.count(words[i][j]))            //letter is already mapped
                           break;
                           
                        //map to the new char
                        mpp[pattern[j]] = words[i][j];
                        st.insert(words[i][j]);
                    }
                    else{
                        //check if char is mapped correctly
                        if(mpp[pattern[j]] != words[i][j])
                            break;
                    }
                    
                    if(j==words[i].size()-1)
                        ans.push_back(words[i]);
                }
            }
        }
        
        return ans;
    }
};