class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        stack<char> st;
        
        for(int i=0; i<=pattern.size(); i++){
            st.push(i+'1'); //1-8
            
            if(pattern.length()==i || pattern[i]=='I'){
                while(!st.empty()){
                    res.push_back(st.top());
                    st.pop();
                }
            }
        }
        
        return res;
    }
};