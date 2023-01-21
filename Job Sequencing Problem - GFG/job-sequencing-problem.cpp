//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a, Job b){
        return a.profit> b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sort by profit(more profit to less profit)
        sort(arr, arr+n, comp);
        
        //-1 means not occupied
        vector<int> res(n+1, -1);
        
        
        //start assigning tasks
        long long profit= 0, cnt=0;
        for(int i=0; i<n; i++){
            int slot = arr[i].dead;
            
            //check from deadline a free slot where this task can be assigned
            while(slot>0){
                if(res[slot]==-1){
                    res[slot] = arr[i].id;
                    profit += arr[i].profit;
                    cnt++;
                    break;
                }
                slot--;
            }
        }
        
        return {cnt, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends