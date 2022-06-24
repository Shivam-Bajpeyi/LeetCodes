class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> rotated(n, vector<int>(n));
        
        int k = n-1;    //last col
        //take row and place it from the last to 1st col
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                rotated[j][k] = matrix[i][j];        
            }
            k--;
        }
        
        matrix = rotated;
    }
};