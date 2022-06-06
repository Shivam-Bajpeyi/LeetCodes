class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //ransomeNote can be constructed from magazine if magazine contains all the letter used in making ransomeNote
        
        //store all the char of magazine so that it can be searched easily
        unordered_map<char, int> mpp;
        for(int i=0; i<magazine.size(); i++){
            mpp[magazine[i]]++;
        }
        
        //iterate ransomeNote 
        for(int i=0; i<ransomNote.size(); i++){
            if(mpp[ransomNote[i]] >= 1)    //magazine does not have this char of ransomeNote
                mpp[ransomNote[i]]--;   //No, ransomNote can't be constructed
            else
                return false;
        }
        
        return true;
    }
};