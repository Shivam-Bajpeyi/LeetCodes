class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> number;    //to store number 123
        int fact = 1;
        for(int i=1; i<n; i++){ //12
            fact = fact*i;
            number.push_back(i);
        }
        
        number.push_back(n);    //3
        k = k-1;                //0-based index
        
        //make kth permutation
        string ans = "";
        while(true){
            ans += to_string(number[k/fact]);      //2
            
            //erase chosen digit from number
            number.erase(number.begin()+ k/fact);  //number = [1 3]
            
            if(number.size()==0)    //permutation formed
                break;
            
            //update fact
            k = k%fact;                 //new k = 1
            fact = fact/ (number.size());
        }
        
        cout<<ans;
        return ans;
    }
};