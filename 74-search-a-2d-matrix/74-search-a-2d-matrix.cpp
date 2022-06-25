class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int j = m-1;    //last col
        int i=0;
        
        while(i<n && j>=0){
            if(matrix[i][j]== target)
                return true;
            
            else if(matrix[i][j] > target){ //target is not in this row, go to next row
                j--; 
            }
            else{
                i++;
            }
        }
        
        return false;
    }
};