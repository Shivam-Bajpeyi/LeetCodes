//color all image[sr][sc] as color
//dfs approach

class Solution {
public:
    void helper(vector<vector<int>> &mat, int i, int j, int color, int iniColor){
        if(i<0 || j<0 || i>= mat.size() || j>= mat[0].size())
            return;
        
        if(mat[i][j] != iniColor || mat[i][j]== color)
            return;
        
        //explore: check in 4 directions for iniColor and change it to color
        mat[i][j] = color;
        
        helper(mat, i-1, j, color, iniColor);
        helper(mat, i+1, j, color, iniColor);
        helper(mat, i, j-1, color, iniColor);
        helper(mat, i, j+1, color, iniColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> mat = image;    
        helper(mat, sr, sc, color, iniColor);
        
        return mat;
    }
};