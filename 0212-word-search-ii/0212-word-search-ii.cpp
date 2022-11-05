class Solution {
public:
  class Trienode{
            public:
            Trienode *children[26];
            string word;
        Trienode()
        {
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
                
            }
            word="";
        }
        Trienode* putinTrie(Trienode *node,char ch)
        {
            Trienode *newnode=new Trienode();
            node->children[ch-'a']=newnode;
            return newnode;
        }
  };
class Trie{
    public:
    Trienode *root;
    
    Trie()
    {
        root=new Trienode();
    }
    void insertInTrie(string word)
    {
        Trienode *node=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(node->children[ch-'a']!=NULL)
            {
                node=node->children[ch-'a'];
            }
            else
            {
                node=node->putinTrie(node,ch);
            }
        }
        node->word=word;
    }
    void dfs(vector<vector<char>>& board, int i, int j,Trienode *curr,  vector<string>& result) 
    {    
        char c = board[i][j];
        if(c == '@' || curr->children[c - 'a'] == NULL) return;
        curr = curr->children[c - 'a'];
        if (curr->word != "") {
            result.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '@';
        if(i > 0) dfs(board, i - 1, j , curr, result); 
        if(j > 0) dfs(board, i, j - 1, curr, result);
        if(i < board.size() - 1) dfs(board, i + 1, j, curr, result); 
        if(j < board[0].size() - 1) dfs(board, i, j + 1, curr, result); 
        board[i][j] = c;
    }

};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *t=new Trie();
        vector<string>result;
        for(int i=0;i<words.size();i++)
        {
            t->insertInTrie(words[i]);
        }
        for(int i = 0; i < board.size(); ++i) 
        {
            for(int j = 0; j < board[0].size(); ++j) 
            {
                t->dfs(board, i, j,t->root, result);
            }
        }

        return result;
    }
};