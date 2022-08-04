class Solution {
public:
    int myAtoi(string s) {
        //step-1: removing leading whitespace
        int i= 0;
        while(i<s.size() && s[i]== ' ')
            i++;
        
        //step-2: check sign
        int sign = 1;
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }
        
        //step-3: make the number by taking digit
        int max = INT_MAX, min = INT_MIN;
        long number = 0;
        //if we are getting digit then only add 
        while(i<s.size() && s[i]- '0' >=0 && s[i]-'0'<=9){    //digit = 0-9
            number = number*10 + s[i]- '0';
            // cout<<s[i]-'0'<<endl;
            if(sign*number <min) return min;
            if(sign*number > max) return max;
            
            i++;
        }
          
        //step-4: return ans
        return (int) sign* number;
        
    }
};