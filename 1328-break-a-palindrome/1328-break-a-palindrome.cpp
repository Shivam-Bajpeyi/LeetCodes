class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        
        //find a non 'a'  and change that to 'a'
        for(int i=0; i<n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }     
        }
        
        //if there is all 'a', change last char to 'b'
        palindrome[n-1] = 'b';
        return palindrome;
    }
};