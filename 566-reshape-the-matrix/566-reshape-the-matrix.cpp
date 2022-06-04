class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n= mat[0].size();
        if(r*c != m*n)      
            return mat;
        
        //store all the elements in list
        vector<int> list;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                list.push_back(mat[i][j]);
            }
        }
        
        int k= 0;
        vector<vector<int>> nums(r, vector<int>(c));    //make a new reshaped matrix 
        
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    nums[i][j] = list[k++];     
                }
            }
        
        
        return nums;
        
    }
};