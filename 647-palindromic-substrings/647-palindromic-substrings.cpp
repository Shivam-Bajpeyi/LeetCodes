class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        
        //generate substrings and check for palindrome
        for(int i=0; i<s.size(); i++){
            string str = "";
            for(int j=i; j<s.size(); j++){
                str += s[j];
                if(isPalindrome(str))
                    cnt++;
            }
        }
        
        return cnt;
    }
    
    bool isPalindrome(string str){
        int l = 0, r = str.size()-1;
        while(l<=r){
            if(str[l++] != str[r--])
                return false;
        }
        return true;
    }
};