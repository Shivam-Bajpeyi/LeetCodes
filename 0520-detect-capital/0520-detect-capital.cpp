class Solution {
public:
    bool allCap(string word){
        for(int i=0; i<word.size(); i++){
            if(word[i]>=97 && word[i]<=122) //lower case letter
                return false;
        }
        return true;
    }
    
    bool allSmall(string word){
        for(int i=0; i<word.size(); i++){
            if(word[i]>=65 && word[i]<=90) //upper case letter
                return false;
        }
        return true;
    }
    
    bool firstCap(string word){
        //first capital
        if(word[0] >=97 && word[0]<=122) return false;
        
        //rest small
        for(int i=1; i<word.size(); i++){
            if(word[i]>=65 && word[i]<=90) //lower case letter
                return false;
        }
        return true;
    }
    
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        if(allCap(word) || allSmall(word) || firstCap(word))
            return true;
        return false;
    }
};