class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window approach
        int length = 0;
        int start = 0, i=0;
        
        //map will store current index of every character in string
        vector <int> map(256, -1);
        
        //iterate over string to find longest substring
        for(i = 0; i<s.size(); i++)
        {
            if(map[s[i]] != -1)   //if this char occurs previouslu
                start = max(start, map[s[i]]+1);  //update start point
            
            map[s[i]] = i;      //update index of char every time
            length = max(length, i-start+1);    //update length
                
        }
        
        return length;
    }
};