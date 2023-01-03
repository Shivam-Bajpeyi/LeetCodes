//n = total length
//window_size = max sliding window size means these many are the max element that we can remove to get minimum ans 
//ans = n - window_size;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mpp;
        
        //count freq of each char
        for(auto &it: s)
            mpp[it]++;
        
        if(mpp['a']<k || mpp['b']<k || mpp['c']<k)
            return -1;
        
        //check max window size now
        int window= 0, mini= INT_MAX, j= 0;
        for(int i=0; i<n; i++){
            mpp[s[i]]--;
            window++;
            
            //if this element can't be include in sliding window then backup char frequemcies and make window empty and try forming new window
            while(mpp[s[i]]<k){
                mpp[s[j++]]++;
                window--;
            }
            
            //whatever window we are getting take mini every time
            //mini will be the value for max window_size
            mini = min(mini, (n-window));
        }
        
        return mini;
    }
};