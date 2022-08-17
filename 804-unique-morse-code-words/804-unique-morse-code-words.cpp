class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> strs = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        //to store number of unique stringd generated
        set<string> st;
        
        for(auto &it: words){
            string encode;
            for(auto &jt: it){
                encode += strs[jt-'a'];
            }
            st.insert(encode);
        }
        
        //total unique encode strings
        return st.size();
    }
};