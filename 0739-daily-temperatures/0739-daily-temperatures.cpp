class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;   //monotonic stack(increasing-> top to down)
        int n = temp.size();
        
        st.push({temp[n-1], n-1});        //(73, 7)
        vector<int> res(temp.size());
        
        for(int i=res.size()-2; i>=0; i--){
            while(!st.empty() && temp[i]>= st.top().first)
                st.pop();   //pop out smaller values
            
            if(st.empty())
                res[i] = 0;
            else
                res[i] = st.top().second- i;        
                
            st.push({temp[i], i});
        }
        
        return res;
    }
};