class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j, string word, int idx){
        if(idx>=word.size())return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[idx])return false;
        board[i][j]='0';
        bool up =dfs(board, i-1, j, word, idx+1);
        bool down=dfs(board, i+1, j, word, idx+1);
        bool left=dfs(board, i, j-1, word, idx+1);
        bool right=dfs(board, i, j+1,word, idx+1);
        if(up or down or left or right)return true;
        board[i][j]=word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, i, j, word, 0))return true;
                }
            }
        }
        return false;
        
    }
};