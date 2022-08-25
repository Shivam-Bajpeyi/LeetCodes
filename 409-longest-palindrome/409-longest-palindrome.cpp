//take all letter that has even number of freq and take one letter that has 1 freq in the middle

class Solution {
public:
    int longestPalindrome(string s) {
        //store freq
        unordered_map<int, int> mpp;
        
        for(auto &it: s)
            mpp[it]++;
        
        int ans = 0;
        bool flag = 0;  //1 middle element that has exact one occurence
        for(auto &it: mpp){
            cout<<it.second<<endl;
            ans += (it.second/2)*2; //even occurence accepted
            
            //finding middle element: single element can be placed at middle
            if(flag==0 && it.second%2){
                ans++;
                flag =1 ;
            }
        }

        return ans;
    }
};