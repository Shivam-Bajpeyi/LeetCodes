//TC = O(N*M)
//SC = O(M) + O(N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        //make row & col vector to keep track which row and col has 0 element
        vector<int> row(m, -1);
        vector<int> col(n, -1);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] ==0){   //mark ith row and jth col = 0
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        //since we know that which row or col has 0 then its time to go throgh all the elements and if element belongs to that row/ col which have 0 make that element 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i]==0 || col[j]==0)
                    matrix[i][j]= 0;
            }
        }
    }
};