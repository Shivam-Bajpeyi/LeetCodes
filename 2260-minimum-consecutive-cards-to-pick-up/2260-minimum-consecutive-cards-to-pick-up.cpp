class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        vector<int> occur(1e6+1, -1);
        int mn = INT_MAX;
        for(int i=0; i<cards.size(); i++){
            if(occur[cards[i]] != -1){   //element occuring more than one time
                mn  = min(mn, i- occur[cards[i]]+1);
           }
           
           occur[cards[i]] = i;
       }
        
        return mn==INT_MAX ? -1 : mn;
    }
};