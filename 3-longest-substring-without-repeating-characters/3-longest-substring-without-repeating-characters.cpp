class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hashmap to store latest index of char 
        unordered_map<char, int> mpp;
        
        int l=0; //starting point
        int mxLen = 0;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i]) != mpp.end()){    //duplicate found in substr
                //update string starting point
                l = max(l, mpp[s[i]]+1);
            }
            
            //calc mxLen
            mxLen = max(mxLen, i-l+1);
            mpp[s[i]] = i;  //update index
        }
        
        return mxLen;
    }
};