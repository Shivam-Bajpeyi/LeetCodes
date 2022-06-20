class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> ans;
        
        vector<vector<int>> triangle(numRows);
        
        //make triangle
        for(int i=0; i<numRows; i++){
            //at each level elements are (level+1)
            triangle[i].resize(i+1);
            
            //make corners 1 of every level
            triangle[i][0] = triangle[i][i] = 1;
            
            //fill middle elements = triangle[i-1][j]+ triangle[i-1][j-1]
            for(int j=1; j<i; j++){
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        
        return triangle;
    }
};