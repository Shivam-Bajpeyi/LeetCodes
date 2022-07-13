// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a, Item b){
        double val1 = (double)a.value/ (double)a.weight;
        double val2 = (double) b.value/ (double)b.weight;
        
        return val1> val2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double total = 0;
        
        //sort in decreasing v/w fashion
        sort(arr, arr+n, comp);
        
        //fill knapsack
        int i=0;
        for(int i=0; i<n; i++){
            if(W>= arr[i].weight){
                W -= arr[i].weight;
                total += arr[i].value; 
            }
            else{
                total += ( (double)arr[i].value / (double)arr[i].weight) *(double)W; 
                break;
            }
        }
        
        return total;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends