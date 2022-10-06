class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //new matrix
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        //initial config: copy first row & col
        for(int i=0; i<n; i++)  mat[i][0] = matrix[i][0];       //row
        for(int j=0; j<m; j++)  mat[0][j] = matrix[0][j];       //col
        
        //take min(3 dir)+1
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==0) mat[i][j]= 0;
                else
                    mat[i][j] = min(mat[i-1][j], min(mat[i-1][j-1], mat[i][j-1]))+1;
            }
        }
        
        //count
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt += mat[i][j];
            }
        }
        
        return cnt;
    }
};