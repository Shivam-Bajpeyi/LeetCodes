//Binary search solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        //low = 1st element, high = last element 
        //since the matrix is sorted so treat it as a 1d array and BS to find target
        int low = 0;
        int high = m*n-1;
        
        while(low<= high){
            int mid = (low+high)>>1;
            
            // cout<< mid <<" "<<matrix[mid/n][mid%n]<<endl;
            
            if(matrix[mid/n][mid%n]== target) return true;
            
            else if(matrix[mid/n][mid%n] > target)    //check in left half, high = mid-1
                high = mid-1;
            else            
                low = mid+1;       //check in right half, low= mid+1;
        }   
        
        return false;
    }
};