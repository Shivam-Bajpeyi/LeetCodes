//PLE(previous less element), NLE(next less element)
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0, n= arr.size();
        
        //monotonic stack (increasing)
        stack<pair<int, int>> st;
        
        //left(to store distance btw i and PLE), right(to store distance btw i and NLE)
        vector<int> left(n), right(n);
        
        //PLE
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first> arr[i])
                st.pop();
            
            //left[i] is the distance in left till arr[i] is smaller
            left[i] = (st.empty()) ? i+1 : (i-st.top().second);   //push the dist btw i and index of PLE
            
            // cout<<left[i]<<" ";
            st.push({arr[i], i});
        }
        
        //empty the stack to use further
        while(!st.empty())
            st.pop();
        
        //NLE
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>= arr[i])
                st.pop();
            
            //right[i] is the distance in right till arr[i] is smaller
            right[i] = (st.empty()) ? n-i : (st.top().second-i);   //push the dist btw i and index of NLE
            
            // cout<<right[i]<<" ";
            st.push({arr[i], i});
        }
        
        
        //ans += arr[i]*left[i]*right[i]
        for(int i=0; i<n; i++){
            long long prod = (left[i]*right[i])%mod;
            prod = (prod*arr[i])%mod;
            ans = (ans + prod)%mod;   
        }
        return ans;
    }
};