class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]== b[0]) return a[1]> b[1];
        
        return a[0]< b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //sort acc to increasing attack (decreasing defence for same attack value)
        sort(properties.begin(), properties.end(), cmp);
        
        int cnt = 0;
        int mini = INT_MIN;
        
        int n = properties.size();
        //start from the back and count when any i[1]< maximum defence value 
        for(int i=n-1; i>=0; i--){
            if(properties[i][1]< mini)  //if its defence too smaller than someone
                cnt++;
            else
                mini = max(mini, properties[i][1]);
        }
        
        return cnt;
    }
};