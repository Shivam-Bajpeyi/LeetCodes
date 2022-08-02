class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        
        //map symbol to value
        mpp['I'] = 1;   mpp['V'] = 5;   mpp['X'] = 10;
        mpp['L'] = 50;  mpp['C'] = 100; mpp['D'] = 500; mpp['M'] = 1000;
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i<n-1 && s[i]== 'I' && (s[i+1]=='V' || s[i+1]=='X')){
                if(s[i+1]== 'V') ans = ans + mpp['V']- mpp['I'];
                else if(s[i+1]== 'X') ans = ans + mpp['X']- mpp['I'];
                i+= 1;
            }
            
            else if(i<n-1 && s[i]== 'X' && (s[i+1]=='L' || s[i+1]=='C')){
                if(s[i+1]== 'L') ans = ans + mpp['L']- mpp['X'];
                else if(s[i+1]== 'C') ans = ans + mpp['C']- mpp['X'];
                i += 1;
            }
                
            else if(i<n-1 && s[i]== 'C' && (s[i+1]=='D' || s[i+1]=='M')){
                if(s[i+1]== 'D') ans = ans + mpp['D']- mpp['C'];
                else if(s[i+1]== 'M') ans = ans + mpp['M']- mpp['C'];
                i += 1;
            }
            
            else{
                cout<<s[i]<<" ";
                ans = ans + mpp[s[i]];
            }
                
        }
    
        return ans;
    }
};