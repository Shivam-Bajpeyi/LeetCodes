// 1.recursion
// class Solution {
// public:
//     int f(int i, int j, vector<int>& cuts){
//         if(j<i) return 0;
        
//         int mini = INT_MAX;
//         //cuts in (i, j) blobk
//         for(int ind = i; ind<=j; ind++){
//             int value = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts) + f(ind+1, j, cuts);
//             mini = min(mini, value);
//         }
        
//         return mini;
//     }
    
//     int minCost(int n, vector<int>& cuts) {
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(), 0);
//         sort(cuts.begin(), cuts.end());
        
//         return f(1, cuts.size()-2,  cuts);
//     }
// };


// //2. Memoization
// class Solution {
// public:
//     int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
//         if(j<i) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int mini = INT_MAX;
//         //cuts in (i, j) blobk
//         for(int ind = i; ind<=j; ind++){
//             int value = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
//             mini = min(mini, value);
//         }
        
//         return dp[i][j]= mini;
//     }
    
//     int minCost(int n, vector<int>& cuts) {
//         int m = cuts.size();
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(), 0);
//         sort(cuts.begin(), cuts.end());
        
//         //dp
//         vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
//         return f(1, cuts.size(), cuts, dp);
//     }
// };


//3. Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        //dp
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        //bottom-up
        for(int i=m-2; i>=1; i--){
            for(int j=i; j<=m-2; j++){
                if(j<i) continue;
                
                int mini = INT_MAX;
                //cuts in (i, j) blobk
                for(int ind = i; ind<=j; ind++){
                    int value = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, value);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][cuts.size()-2];
    }
};