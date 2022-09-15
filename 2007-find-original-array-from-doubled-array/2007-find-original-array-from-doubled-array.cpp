class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        int n = changed.size();
        
        if(n%2) return res;     //odd size: can't be a 2*m
        
        //store elements in set for easy search
        unordered_map<int,int> mpp;
        for(int it: changed)
            mpp[it]++;
        
        sort(changed.begin(), changed.end(), greater<int>());
        
        //check if there is double present for exact n/2 elements
        for(int it: changed){
            if(it==1) continue;
            if(it==0 && mpp[0]<2) continue;
            
            if(it%2==0 && mpp[it]>=1 && mpp.find(it/2) != mpp.end() && mpp[it/2]>=1){
                res.push_back(it/2);
                mpp[it/2]--;
                mpp[it]--;
            }
        }
        
        if(res.size()== n/2) return res;
        return {};
    }
};