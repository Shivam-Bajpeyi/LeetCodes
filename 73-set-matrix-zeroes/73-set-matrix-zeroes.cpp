class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //traverse all over the  matrix and make complete row & col -1 for element = 0 wherever we find
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    for(int k=0; k<n; k++)  //entire col = 0
                        if(matrix[i][k] != 0)   matrix[i][k] = 'a';
                    for(int k= 0; k<m; k++) //entire row = 0
                        if(matrix[k][j] != 0)   matrix[k][j] = 'a';
                }
            }
        }
        
        // -1 -> 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='a')
                    matrix[i][j] = 0;
            }
        }
        
        // return matrix;
    }
};