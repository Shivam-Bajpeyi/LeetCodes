class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        //8 char length
        if(password.size() < 8)
            return false;
        
        
        bool lower = 0, upper = 0;
        bool digit = 0, special = 0;
    
        
        //check rest conditions
        for(int i=0; i<password.size(); i++){
            if(i>0){
               //check duplicate
                if(password[i] == password[i-1]) 
                    return false; 
            } 
            
            //uppercase
            if(password[i] >=65 && password[i] <=90) 
                upper = 1;
            
            //lowercase
            else if(password[i] >=97 && password[i] <=122) 
                lower = 1;
            
            //digit
            else if(password[i] >=48 && password[i] <=57) 
                digit = 1;
            
            //special char
            else
                special = 1;
        }
        
        if(upper && lower && digit && special)
            return true;
        return false;
    }
};