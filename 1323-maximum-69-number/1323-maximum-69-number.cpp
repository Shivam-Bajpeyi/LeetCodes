class Solution {
public:
    int maximum69Number (int num) {
        //find total digits
        int temp = num, digits= 0;
        while(temp>0){
            temp/= 10;
            digits++;
        }

        //find first '6' and convert it to 9
        temp = pow(10, digits-1);
        int res =0, flag = 0;
        while(temp>0){
            int x = num/temp;
            x = x%10;               //first digit
            
            // cout<<x<<endl;
            if(flag==0 && x==6){
                x = 9;
                flag = 1;
            }
            
            // cout<<res<<" "<<base<<endl;
            res = res*10 + x;
            temp /= 10;
        }
        
        return res;
    }
};