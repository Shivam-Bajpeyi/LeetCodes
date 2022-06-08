class Solution {
public:
    int removePalindromeSub(string s) 
    {
        int f=0, e=s.size()-1;
      
        while(f<e)
        {
            //if whole string is not palindromic return 2
            if(s[f]!=s[e]) return 2;
            f++;
            e--;
        }
        
        //if whole string is palindromic return 1
        return 1;
    }
};