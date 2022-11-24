class Solution {
public:
    bool dfs(int ind, int i, int j,  vector<vector<char>>& board, string word)
    {
         if(ind == word.size())
            return true;
        
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j] != word[ind])
            return false;
        
        //if(board[i][j]== word[ind]) then search for next letter
        char temp = board[i][j];
        board[i][j] = '.';
        
        bool ans = (dfs(ind+1, i-1, j, board, word) || 
              dfs(ind+1, i+1, j, board, word)|| 
              dfs(ind+1, i, j-1, board, word) || 
              dfs(ind+1, i, j+1, board, word));
        
        board[i][j]= temp;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(0, i, j, board, word))
                    return true;
            }
        }
        
        return false;
    }
};