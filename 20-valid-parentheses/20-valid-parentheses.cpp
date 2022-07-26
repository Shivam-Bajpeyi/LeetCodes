class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        for(auto it: s){
            if(!st.empty() && (it==')' || it=='}' || it==']')){ //close bracket
                if(it==')' && st.top()!= '(') return false;
                if(it=='}' && st.top()!= '{') return false;
                if(it==']' && st.top()!= '[') return false;
                
                st.pop(); //rempve matching open bracket
            }
            else{   //open bracket
                st.push(it);
            }
        }
        
        //if parentheses are balanced
        return st.size()==0;
    }
};