//power array is actually binary representation of 
//n = 5 => 101 => 4 + 1

class Solution {
public:
    int mod= 1e9+7;
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        
        //check set bits and push them in power
        for(int i=0; i<32; i++){
            if(n&(1<<i))                    //set bits
                power.push_back((1<<i));
        }
        
        //execute queries
        vector<int> res;
        for(auto it: queries){
            int left = it[0];
            int right = it[1];
            
            long mul = 1;
            for(int i=left; i<=right; i++){
                mul = (mul*power[i])%mod;
            }
            
            res.push_back(mul);
        }
        
        return res;
    }
};