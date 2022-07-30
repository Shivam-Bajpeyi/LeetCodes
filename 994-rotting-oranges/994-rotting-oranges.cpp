class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    //row
        int m = grid[0].size(); //col
        
        queue<pair<int, int>> q;    //stores index of rotten oranges that are initially present
        
        //find total number of oranges & 
        int total = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!= 0) total++;
                
                //store index of rotten oranges
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        //if no oranges in grid
        if(total==0) return 0;
        
        //start rotting oranges
        //in the queue we are storing rotten oranges, count them to see if count== total oranges
        //after the initially stored rotten oranges, every time it needs 1 min to store another set of rotten orange in queue
        int count = 0;
        int minutes = -1;
        
        while(!q.empty()){
            int size = q.size();
            minutes++;
            count += size;  //add rotten oranges every time we find
            
            while(size--){
                auto k = q.front(); q.pop();
                int i = k.first;    //index of rotten orange
                int j = k.second;   //index of rotten oranges
                
                //see in all 4 direction if there is any fresh orange then make it rotten and store it in queue
                if(j>0 && grid[i][j-1]== 1){//left
                    grid[i][j-1]= 2; q.push({i, j-1});
                }   
                if(j<m-1 && grid[i][j+1]== 1){//right
                    grid[i][j+1]= 2; q.push({i, j+1});
                }     
                if(i>0 && grid[i-1][j]== 1){//up
                    grid[i-1][j]= 2; q.push({i-1, j});
                }     
                if(i<n-1 && grid[i+1][j]== 1){//down
                    grid[i+1][j]= 2; q.push({i+1, j});
                }     
            }
        }
        
        //if we are unable to rotten all the oranges
        if(count!= total) return -1;
        
        //if we have rotten all the oranges
        else    
            return minutes;
        
    }
};