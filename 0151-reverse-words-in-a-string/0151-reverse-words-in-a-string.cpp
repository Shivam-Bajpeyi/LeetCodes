//optimal: reverse the string by taking every word and add it at the start of the ans string
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ')
                temp += s[i];
            
            if(s[i]== ' ' && temp != ""){   //add word to the string
                if(ans == "")
                    ans = temp;
                else
                    ans = temp + " " + ans;
                
                temp = "";
            }
        }
        
        //if last word is left to be add
        if(temp != ""){
            if(ans != "")
                ans = temp + " "+ ans;
            else
                ans = temp;
        }
            
        
        return ans;
    }
};