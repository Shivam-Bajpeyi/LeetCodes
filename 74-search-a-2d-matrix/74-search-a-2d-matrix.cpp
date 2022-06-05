class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0, col = n-1;
        //point at first row, last col value
        
        while(row<m && col>=0){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                row++;
            
            else
                col--;
        }
        
        return false;
    }
};