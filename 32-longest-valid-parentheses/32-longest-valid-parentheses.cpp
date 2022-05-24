class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0;
        stack<int> st;
        st.push(-1);
        
        //iterate over the string to find the longest valid parenthesis
        for(int i=0; i<s.size(); i++){
            if(s[i]== '(')  //'(': push index
                st.push(i);
            
            else{   //')': compute the length of valid parenthesis
                st.pop();
                
                if(st.empty())  //need this index to be pushed because stack is empty now
                    st.push(i);
                
                cnt = max(cnt, i-st.top()); 
                    
            }
                
        }
        
        return cnt;
    }
};