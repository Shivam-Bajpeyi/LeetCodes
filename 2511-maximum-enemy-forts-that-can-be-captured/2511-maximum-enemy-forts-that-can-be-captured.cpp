class Solution {
public:
    int captureForts(vector<int>& forts) {
        //we have to find the max number of zeroes between 1 & -1 or -1 & 1
        int n = forts.size();
        
        int j= 0, res= 0;
        for(int i=0; i<n; i++){
            if(forts[i] != 0){
                if(forts[i] == -forts[j])
                    res = max(res, i-j-1);
                
                j = i;
            }
        }
        
        return res;
    }
};