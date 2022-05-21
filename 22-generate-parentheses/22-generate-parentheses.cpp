class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        helper(0, 0, "", n);
        return ans;
    }
    
    void helper(int openCount, int closeCount, string str, int n){
        if(openCount < n)
            helper(openCount+1, closeCount, str+"(", n);
        
        if(closeCount < openCount)
            helper(openCount, closeCount+1, str+")", n);
        
        if(openCount ==n && closeCount==n)
            ans.push_back(str);
    }
};