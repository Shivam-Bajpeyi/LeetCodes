class Solution {
public:
    //Use two pointers approach
    int countSubstrings(string s) 
    {
        int start, end, count=0, n=s.size();
        
        //iterate over whole string
        for(int i=0; i<n; i++)
        {
            //for odd length palindrome substring
            start=i; end=i;
            while(start>=0 && end<n && s[start--]==s[end++]) count++;
            
            //for even length palindrome substring
            start=i-1; end=i;
            while(start>=0 && end<n && s[start--]==s[end++]) count++;
        }
        
        //return no. of palindrome substrings
        return count;
    }
};