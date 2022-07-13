// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	if(n==1)
    	    return 1;
    	   
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int s=1, e=0, count =1, minPlatform =1;
    	while(s<n){
    	    if(arr[s]<= dep[e]) //one train is arriving & platform is occupied, 
    	    {
    	        count++;    //need one more platform
    	        minPlatform = max(minPlatform, count);
    	        s++;        
    	    }
    	    else{   //one train is departuring, one platform got empty
    	        count--;
    	        e++;
    	    }
    	    
    	}
    	
    	return minPlatform;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends