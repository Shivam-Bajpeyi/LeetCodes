class Solution {
private:
    bool isPossible(int row, int col, vector<string> &board){
        int duprow = row;
        int dupcol = col;
        //check upper left diag
        while(duprow>=0 && dupcol>=0){
            if(board[duprow][dupcol]== 'Q')
                return false;
            duprow--;
            dupcol--;
        }
        
        //left
        duprow = row;
        dupcol = col;
        while(dupcol>=0){
            if(board[duprow][dupcol]== 'Q')
                return false;
            dupcol--;
        }
        
        //lower left diag
        duprow = row;
        dupcol = col;
        while(duprow<board.size() && dupcol>=0){
            if(board[duprow][dupcol]== 'Q')
                return false;
            duprow++;
            dupcol--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans){
        if(col== board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<board.size(); row++){
            if(isPossible(row, col, board)){
                board[row][col] = 'Q';
                solve(col+1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string str(n, '.');
        for(int i=0; i<n; i++){
            board[i] = str;
        }
        
        solve(0, board, ans);
        return ans;
    }
};