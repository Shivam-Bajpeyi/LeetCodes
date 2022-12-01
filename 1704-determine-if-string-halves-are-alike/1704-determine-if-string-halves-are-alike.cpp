class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int n= s.size();
        
        //cnt1 for a
        int cnt1 = 0;
        for(int i=0; i<n/2; i++){
            if(st.count(s[i]))
                cnt1++;
        }
        
        //cnt2 for b
        int cnt2 = 0;
        for(int i=n/2; i<n; i++){
            if(st.count(s[i]))
                cnt2++;
        }
        
        return (cnt1==cnt2);
    }
};