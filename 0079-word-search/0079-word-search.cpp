class Solution {
public:
    int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int row,int col,int index,vector<vector<char>>& board, string&word){
        if(index==word.size()) return true;
        if(row<0|| col<0 || row>=board.size()||col>=board[0].size()||board[row][col]!=word[index]){
            return false;
        }
        char node=board[row][col];
        board[row][col]='$';
        for(int k=0;k<4;k++){
            if(dfs(row+direction[k][0],col+direction[k][1],index+1, board, word))
                return true;
            }
        board[row][col]=node;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                 if(dfs(i,j,0,board,word)){
                    return true;
                 }
            }
        }
        return false;

    }
};