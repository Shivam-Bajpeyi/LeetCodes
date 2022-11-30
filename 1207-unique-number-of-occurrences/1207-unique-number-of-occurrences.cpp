class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        
        //hash the freq
        for(auto &it: arr){
            mpp[it]++;    
        }
        
        //to find unique freq use set
        set<int> st;
        for(auto &it: mpp){
            if(st.count(it.second))
               return false;
            st.insert(it.second);
        }
        
        return true;
    }
};