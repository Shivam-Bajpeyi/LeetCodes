class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;      //monotinic stack
        
        //store nge 
        for(int i=2*n-1; i>=0; i--){
            int j = i%n;
            
            //get to the greater element by removing <= element
            while(!st.empty() && st.top()<=nums[j]){
                st.pop();   
            }
            
            if(st.empty())
                nge[j] = -1;
            else
                nge[j] = st.top();  //get the nge
            
            st.push(nums[j]);   //push current element
                
        }
    
        return nge;
    }
};