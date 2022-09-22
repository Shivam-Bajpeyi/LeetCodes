//without reverse function
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        
        //iterate from the back to get the reversed word and place it in the last
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != ' ')
                word += s[i];
            
            else if(word.size()>=1 && s[i]==' '){
                ans = word + ans;
                ans = " "+ ans;         //adding whitespace as it is
                word = "";          //make it empty
            }
        }
        
        if(word.size()>=1)
            ans = word + ans;
        
        return ans;
    }
};