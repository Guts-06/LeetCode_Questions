class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis){
        int rows=board.size();
        int cols=board[0].size();
        if(i>=rows||j>=cols) return;
        if(i<0||j<0) return;
        if(board[i][j]=='.') return;
        if(vis[i][j]) return;
        vis[i][j]=1;
        dfs(i+1,j,board,vis);
        dfs(i,j+1,board,vis);
        // dfs(i-1,j,board,vis);
        // dfs(i,j-1,board,vis);
        
    }
    int countBattleships(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j]&&board[i][j]=='X'){
                    cnt++;
                    dfs(i,j,board,vis);
                }
            }
        }
        return cnt;
    }
};