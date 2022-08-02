class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        
        //map symbol to value
        mpp['I'] = 1;   mpp['V'] = 5;   mpp['X'] = 10;
        mpp['L'] = 50;  mpp['C'] = 100; mpp['D'] = 500; mpp['M'] = 1000;
        
        int sum = mpp[s[n-1]];
        
        //traversing from the back to front using the map
        for(int i= n-2; i>=0; i--){
            if(mpp[s[i]] < mpp[s[i+1]])     //left < right: IV
                sum -= mpp[s[i]];   //5-1 = 4
            else
                sum += mpp[s[i]];
        }
        
        return sum;
    }
};