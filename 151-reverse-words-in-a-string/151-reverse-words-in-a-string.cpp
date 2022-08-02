class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;  //to store words
        string str = "";
        
        //step-1: store words in stack
        for(int i=0; i<n; i++){
            if(s[i]== ' ' && !str.empty()){
                st.push(str);
                str = "";
            } 
            
            if(s[i] != ' ')
                str += s[i];
        }
        
        if(!str.empty())
            st.push(str);   //last word
        
        //step-2: pop words from stack and store them to reverse the order
        str = "";
        while(!st.empty()){
            str += st.top(); st.pop();
            if(!st.empty())
                str += " ";
        }
        
        return str;
        
    }
};