//check every even and odd length substring
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        
        for(int i=0; i<n; i++){
            //even
            int start = i;
            int end = i+1;
            while(start>=0 && end<n && s[start] == s[end]){
                int len = end- start+ 1;
                if(len > ans.size())
                    ans = s.substr(start, len);
                start--; end++;
            }
            
            //odd
            start = i;
            end = i;
            while(start>=0 && end<n && s[start] == s[end]){
                int len = end-start+1;
                if(len > ans.size())
                    ans = s.substr(start, len);
                
                start--; end++;
            }
        }
        
        return ans;
    }
};