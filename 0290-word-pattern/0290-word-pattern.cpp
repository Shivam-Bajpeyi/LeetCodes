class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec;
        
        //store words in vec
        istringstream ss(str);
        string word; // for storing each word
        while (ss >> word)
        {
            vec.push_back(word);
        }
        
        //check if size is not equal 
        if(pattern.size() != vec.size())
            return false;
        
        //make bijection maps: 1) char -> string 2) string-> char
        unordered_map<char, string> mpp;
        unordered_map<string, char> mpp2;
        
        for(int i=0; i<vec.size(); i++){
            if(mpp.find(pattern[i]) == mpp.end()){
                if(mpp2.find(vec[i]) != mpp2.end())
                    return false;
                mpp[pattern[i]] = vec[i];
                mpp2[vec[i]] = pattern[i];
            }
                
            
            //check coming word with mapped pattern's word
            else if(vec[i] != mpp[pattern[i]])
                return false;
        }
        
        return true;
    }
};