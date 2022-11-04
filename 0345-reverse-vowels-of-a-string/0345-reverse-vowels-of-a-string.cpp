class Solution {
public:
    string reverseVowels(string s) {
        set<char> st = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};  //vowels(lo & up)
            
        int i= 0, j= s.size()-1;
        while(i<j){
            while(i<j && !st.count(s[i])){
                // cout<<s[i]<<" ";
                i++;
            }
                
            while(i<j && !st.count(s[j])){
                // cout<<s[j]<<" ";
                j--;
            }
            
            swap(s[i++], s[j--]);
        }
        
        return s;
    }
};