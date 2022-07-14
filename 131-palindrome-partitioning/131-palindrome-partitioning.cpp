class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        
        f(0, s, temp, ans);
        return ans;
    }
    
    void f(int ind, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(ind==s.size()){  //partition for last char done
            ans.push_back(temp);
            return;
        }
         
        for(int i=ind; i<s.size(); i++){
            if(Ispalindrome(s.substr(ind, i-ind+1))){   //mark partition for palindrome substr
                temp.push_back(s.substr(ind, i-ind+1)); //store that
                f(i+1, s, temp, ans);                   //get next partitions from next index
                temp.pop_back();                        //pop one partition while returning
            }
        }
    }
    
    bool Ispalindrome(string str){
        int i= 0;
        int j = str.size()-1;
        
        while(i<j){
            if(str[i++] != str[j--])
                return false;
        }
        
        return true;
    }
};