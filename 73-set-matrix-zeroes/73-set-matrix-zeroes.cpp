//TC = O(N*M)
//SC = O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
    //use matrix first row as row[] & first col as col[] and since matrix[0][0] is overlapping so 
    //we wil use a variable col0 to check zero in 1st col and matrix[0][0] will be used to check 1st row
        int col0 = 1;
        
        //mark ith row and jth col as 0 if found 0 at matrix[i][j] place
        for(int i=0; i<m; i++){
            if(matrix[i][0] ==0) col0 = 0; //col0 has 0 value
            
            for(int j=1; j<n; j++){
                if(matrix[i][j] ==0){   //mark ith row and jth col = 0
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //since we know that which row or col has 0 then its time to go throgh all the elements and if element belongs to that row/ col which have 0 make that element 0
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=1; j--){
                if(matrix[i][0] ==0 || matrix[0][j]==0)
                    matrix[i][j]= 0;
            }
            if(col0==0)  //make 1st col 0 if col0 contains 0
                matrix[i][0] = 0;
        }
    }
};