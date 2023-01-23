//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void generate(int ind, vector<int> arr, int sum){
        if(ind<0){
            res.push_back(sum);
            return;
        }
        
        //generate all subsets: notpick- pick
        generate(ind-1, arr, sum);
        generate(ind-1, arr, sum+arr[ind]);
    }
    
    vector<int> res;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        generate(N-1, arr, 0);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends