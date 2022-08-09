class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        //make a bigger than b to check if b is a substr of a or not
        int cnt = 1;
        string add = a;
        while(a.size()<= b.size()){
            a +=add;
            // cout<<a<<endl;
            cnt++;
        }
           
        a+= add;
        cnt++;
        // cout<<a<<endl;
        //match b with a 
        for(int i=0; i<a.size(); i++){
            //if first letter is matched, check for whole b  
            if(b[0]== a[i] && a.substr(i, m)==b){
                // cout<<a.size()<<endl;
                int repeated = cnt - (a.size()-(i+m))/n;    //3- 2/4 = 3
                return repeated;
            }
        }
        
        return -1;
    }
};