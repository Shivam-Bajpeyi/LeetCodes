// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
#include <string>
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp = "";
        f(0, 0, temp, ans, n, m);
        return ans;
    }
    
    void f(int i, int j, string temp, vector<string> &ans, int n, vector<vector<int>> &m){
        //boundary condition
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]!= 1)
            return;
            
        //push path 
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        //up
        int real = m[i][j];
        m[i][j] = 2;
        f(i-1, j, temp+"U", ans, n, m);
        m[i][j] = real;
        
        //down
        real = m[i][j];
        m[i][j] = 2;
        f(i+1, j, temp+"D", ans, n, m);
        m[i][j] = real;
        
        //left
        real = m[i][j];
        m[i][j] = 2;
        f(i, j-1, temp+"L", ans, n, m);
        m[i][j] = real;
        
        //right
        real = m[i][j];
        m[i][j] = 2;
        f(i, j+1, temp+"R", ans, n, m);
        m[i][j] = real;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends