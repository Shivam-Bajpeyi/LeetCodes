class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        //step1- wherever we find 0, convert all its row and col elements to 'A' (except 0)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++)  //make row A
                        if(matrix[k][j] != 0)
                            matrix[k][j] = 'A';
                    
                    for(int k=0; k<n; k++)  //make col A
                        if(matrix[i][k] != 0)
                            matrix[i][k] = 'A';
                }
                    
            }
        }
        
        //step2- convert back A to 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]== 'A')
                    matrix[i][j] = 0;
            }
        }
    }
};