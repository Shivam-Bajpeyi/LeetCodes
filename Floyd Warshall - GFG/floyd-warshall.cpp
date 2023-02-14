//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    //set up matrix initially
	    int n = matrix.size();
	    
	    //-1 = there is no edge so convert it to a max value
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	            if(i==j)
	                matrix[i][j] = 0;
	        }
	    }
	    
	    //Floyd Warshall: go via every node O(N^3)
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via]+ matrix[via][j]);
	            }
	        }
	    }
	    
	    //if graph has negative cycle, how to detect?
	    //self loop node->node is 0 so if it is -ve then it has -ve cycle
	   // for(int i=0; i<n; i++){
	   //     if(matrix[i][i] <0)
	   //         return -1;
	   // }
	    
	    
	    //convert back 1e9 -> -1
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends