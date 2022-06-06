class Solution {
public:
    int firstUniqChar(string s) {
        int idx = -1;
        
        //store frequency of each element
        unordered_map<int, int> freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]] == 1) //non-repeating element will have frequency 1
                return i;
        }
        
        return idx;
    }
};