class Solution {
public:
    bool isPossible(int row, int col, char c,  vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i]== c)   
                return false;   //row check
            if(board[i][col]== c)   
                return false;   //col check
            
            //third condition 3*3 box
            if(board[3* (row/3) + i/3] [3* (col/3) + i%3]== c)  
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.')
                {
                    for(char c= '1'; c<='9'; c++)
                    {  //which number should be put out of 1-9 ?
                        if(isPossible(i, j, c, board))
                        { //this number can be put here
                            board[i][j] = c;
                            
                            if(solve(board)== true)
                                return true;
                            else                            //backtrack
                                board[i][j]= '.';
                        }
                    }
                    return false;   //when for a position no digit is valid
                }
            }
        }
        
        return true;    //all blank cells have been filled

    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};