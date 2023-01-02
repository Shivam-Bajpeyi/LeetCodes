class Solution {
public:
    string customSortString(string order, string s) {
        //hash string s
        unordered_map<char, int> mpp;   
        for(auto &it: s){
            mpp[it]++;
        }
       
        //ans = make strings with letters with high -> lower priority
        //ans2 = string whose letters have no priority set
        string ans = "";
        string ans2 = "";
        
        //ans
        for(auto &it: order){
            //if the priority letter is present in s then add it 
            if(mpp.find(it) != mpp.end()){
                while(mpp[it]>0){
                    ans += it;
                    mpp[it]--;
                }
            }
        }
        
        //ans2 = collect non-priority letters(freq != 0)
        for(auto &it: s){
            if(mpp[it]!=0){
                while(mpp[it]>0){
                    ans2 += it;
                    mpp[it]--;
                }
            }
        }
        
        return ans+ans2;
    }
};