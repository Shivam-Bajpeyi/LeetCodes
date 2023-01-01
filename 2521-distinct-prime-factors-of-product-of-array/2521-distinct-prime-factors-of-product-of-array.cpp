class Solution {
public:
    int primeFactors(int &prod, int num, set<int> &st){
        int cnt = 0;    //2 is the first prime factor
        
        while(prod>1){
            if(prod%num == 0){
                st.insert(num);
                cnt++;
                while(prod>1 && prod%num==0)
                    prod /= num;
            }
            
            else{
                num++;
            }
        }
        return cnt;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        
        for(int i=0; i<nums.size(); i++){
            primeFactors(nums[i], 2, st);
        }
        
        return st.size();
    }
};