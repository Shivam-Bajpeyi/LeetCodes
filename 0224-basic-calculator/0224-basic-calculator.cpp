class Solution {
public:
    int calculate(string s) {
        int sign=1;
        int sum=0;
        stack<int> st;

        for(int i=0;i<s.size();i++){
            //if the value is number, then find the number as it can be more than a digit
            if(s[i]>='0' and s[i]<='9'){
                int num=0;
                while(i<s.size() and s[i]>='0' and s[i]<='9'){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                sum+=num*sign;
                i--;
            }
            //if encountered + sign make global operator as positive ie 1.
            else if(s[i]=='+') sign=1;
            //if encountered - sign make global operator as negative ie -1.
            else if(s[i]=='-') sign=-1;

            //if open bracket, that means we have to first evaluate the elements inside the brackets,
            //so push the element and sign before brackets in the stack 
            else if(s[i]=='('){
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            //if closed bracket, that means we have evaluated bracket expression so pop the first two
            //element that is prev sum and prev sign from the stack and add to the current sum. 
            else if(s[i]==')'){
                sum*=st.top();
                st.pop();
                sum+=st.top();
                st.pop();
            }
        }
        return sum;
    }
};