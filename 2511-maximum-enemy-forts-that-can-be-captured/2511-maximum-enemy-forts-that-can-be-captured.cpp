class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = INT_MIN;
        
        //left to right
        for(int i=0; i<n; i++){
            if(forts[i] != 1) continue;
            if(i<n-1 && forts[i+1]!= 0)
                continue;
            
            i++;
            int temp = 0;
            while(i<n-1 && forts[i]==0){
                temp++;
                i++;
            }      
            if(i<n && forts[i]== -1){
                ans = max(ans, temp);
            }    
            else
                i--;
        }
        
        //right to left
        for(int i=n-1; i>=0; i--){
            if(forts[i] != 1) continue;
            if(i>0 && forts[i-1]!= 0)
                continue;
            
            i--;
            int temp = 0;
            while(i>0 && forts[i]==0){
                temp++;
                i--;
            }
            // cout<<temp<<" ";
            if(i>=0 && forts[i]== -1){
                ans = max(ans, temp);
                // cout<<ans;
            }    
            else
                i++;
        }
        
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};