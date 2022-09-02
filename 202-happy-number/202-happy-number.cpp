class Solution {
public:
    bool isHappy(int n) {
        //to track if same number come twice, then directly return false;
        set<int> st;
        
        while(n != 1){
            if(st.count(n)) return false;
            st.insert(n);
            
            int temp = n;
            int num = 0;
            while(temp){
                int digit = temp%10;     //digit
                temp = temp/10;         //remaining n
                num += pow(digit, 2);
            }
            
            n = num;
        }
        
        return true;
    }
};