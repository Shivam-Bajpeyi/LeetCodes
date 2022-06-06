class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        //t will be anagram of s if every element of s present in t
        //store  frequency of all char of t in hashmap
        unordered_map<char, int> freq;
        for(int i=0; i<t.size(); i++){
            freq[t[i]]++;
        }
        
        //iterate over s to check every element of s whether present in t or not
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]] >=1)
                freq[s[i]]--;
            else
                return false;
        }
        
        return true;
    }
};