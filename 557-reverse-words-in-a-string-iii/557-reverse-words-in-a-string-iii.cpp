class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        //pick each word and push in ans by reversing it and preserve whitespaces
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ')
                temp += s[i];
            else{
                reverse(temp.begin(), temp.end());
                ans+= temp;
                ans+= " ";
                temp = "";
            }
        }
        
        if(temp.size()>=1){
            reverse(temp.begin(), temp.end());
            ans+= temp;
        }
            
        
        return ans;
    }
};