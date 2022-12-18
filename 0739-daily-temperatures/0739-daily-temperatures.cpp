class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;      //monotonic stack
        vector<int> ans(n, 0);
        
        //find Next Greater Element 
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temp[st.top()]<= temp[i]) 
                st.pop();   //remove days with low temp
            
            if(!st.empty())
                ans[i] = st.top()- i;
            st.push(i);
        }
            
        return ans;
    }
};