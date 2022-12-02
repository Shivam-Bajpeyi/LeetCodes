class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //if the sizes are unequal we can never make word1 -> word2 using any operation
        if(word1.size() != word2.size())
            return false;
        
        //if freq of char are same in both strings, we can make the word1 -> word2
        unordered_map<char, int> mpp1;
        for(auto &it: word1)
            mpp1[it]++;
        
        unordered_map<char, int> mpp2;
        for(auto &it: word2){
            if(!mpp1.count(it))
                return false;           //if the char present in word2 not in word1
            mpp2[it]++;
        }
            
        
        //storing freq of char in vectors
        vector<int> v1, v2;
        for(auto &it: mpp1)
            v1.push_back(it.second);
        for(auto &it: mpp2)
            v2.push_back(it.second);
        
        //sort them to compare
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        if(v1.size() != v2.size())
            return false;
        
        //compare
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i])
                return false;
        }
        
        return true;
    }
};