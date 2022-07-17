class Solution {
private:
    void solve(int col, vector<string> &board,  vector<int> &leftRow, vector<int> &lowerDiag, vector<int> &upperDiag, vector<vector<string>> &ans){
        if(col== board.size()){
            ans.push_back(board);
            return;
        }
    
        
        for(int row=0; row<board.size(); row++){
            if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[board.size()-1 + col-  row]==0){    //is it possible to place queen here
                board[row][col] = 'Q';  
                leftRow[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[board.size()-1+ col- row] = 1;
                solve(col+1, board, leftRow, lowerDiag, upperDiag, ans);   //time to place next queen in the next col
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[board.size()-1+ col- row] = 0;
            } 
        }
    
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string str(n, '.');
        for(int i=0; i<n; i++)
            board[i] = str;
        
        vector<int> leftRow(n, 0), lowerDiag(2*n-1, 0), upperDiag(2*n-1, 0);
        solve(0, board, leftRow, lowerDiag, upperDiag, ans);
        return ans;
    }
};