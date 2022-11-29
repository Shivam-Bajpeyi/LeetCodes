class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size(), m= board[0].size();
        
        //mark O's that can not be captured
        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        //queue to store borders' O
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //collect O's at borders
                if(i== 0 || j==0 || i==n-1 || j== m-1){
                    if(board[i][j] == 'O'){
                        // cout<<i<<" "<<j<<endl;
                        q.push({i, j});
                        vis[i][j]= 1;
                    }
                }
            }
        }
        
        //BFS
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto topp = q.front();
                q.pop();
                int i= topp.first;
                int j= topp.second;
                
                // cout<<i<<" "<<j<<endl;
                
                //4 dir
                if(i-1>=0 && vis[i-1][j]==-1 && board[i-1][j]=='O'){
                    q.push({i-1, j});
                    vis[i-1][j] = 1;
                } 
                if(i+1<n && vis[i+1][j]==-1 && board[i+1][j]=='O'){
                    q.push({i+1, j});
                    vis[i+1][j] = 1;
                } 
                if(j-1>=0 && vis[i][j-1]==-1 && board[i][j-1]=='O'){
                    q.push({i, j-1});
                    vis[i][j-1]= 1;
                } 
                if(j+1<m && vis[i][j+1]==-1 && board[i][j+1]=='O'){
                    q.push({i, j+1});
                    vis[i][j+1]= 1;
                } 
            }
        }
        
        //mark every cell as 'X' except vis[i][j]==1
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 1){
                    // cout<<i<<" "<<j<<endl;
                    board[i][j] = 'X';
                }
            }
        }
    }
};