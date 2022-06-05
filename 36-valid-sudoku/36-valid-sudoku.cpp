class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!isValid(board, i, j, board[i][j])){   //if this char is not valid 
                        return false;
                    }
                }    
            }
        }
                       
        return true;
    }
                       
    bool isValid(vector<vector<char>>& board, int r, int c, char ch){
        //check row
        for(int i=0; i<9; i++){
            if(i!=r && board[i][c] == ch)   //return false, if any other same digit find at any other place in this row
                return false;
        }
        
        //check col
        for(int j=0; j<9; j++){
            if(j!=c && board[r][j]==ch)    //return false, if any other same digit find at any other place in this col
                return false;
                
        }
        
        //check block 3*3
        int ri = 3*(r/3);   //initial point of row of the 3*3 block
        int ci = 3*(c/3);   //initial point of col of the 3*3 block
        
        for(int i=ri; i<ri+3; i++){
            for(int j=ci; j<ci+3; j++){
                if(i!=r && j!=c && board[i][j]==ch) //return false if, ch occurs at any place in this 3*3 block except its own place
                    return false;
            }
        }
        
        return true;
    }
};