//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        //prefix sum approach
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(mpp.find(sum)!= mpp.end()){
                ans = max(ans, i-mpp[sum]);
            }
            else
                mpp[sum]= i;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends