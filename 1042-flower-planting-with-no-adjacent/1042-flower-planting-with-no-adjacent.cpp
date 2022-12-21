class Solution {
public:
    //greedy
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //make adj list
        vector<int> adj[n+1];
        for(auto &it: paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        //A garden can have 3 connected gardens at max so go on every single garden and check what all
        //types do its neighbours have so remaining any type can be taken from all 4
        vector<int> res(n, 0);
        for(int i=1; i<=n; i++){
            //mark neighbours color types
            vector<bool> type(5, 0);
            type[res[i-1]]= res[i-1];
            for(auto &it: adj[i]){
                if(res[it-1])
                    type[res[it-1]]= 1;
            }
                
            //check out of 4 which one left, paint that type 
            for(int j=1; j<=4; j++){
                if(type[j]==0){
                    res[i-1] = j;
                    break;
                }
            }
        }
        
        return res;
    }
};