class Solution {
public:
    int f(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(row<0||col1<0||col2<0||row>=grid.size()||col1>=grid[0].size()||col2>=grid[0].size()){
            return -1e7;
        }
        int ans=0;
        if(col1==col2){
            ans=grid[row][col1];
        }
        else{
            ans=grid[row][col1]+grid[row][col2];
        }
        if(row==grid.size()-1){
            if(col1==col2){
                return grid[row][col1];
            }
            else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
        int res=0;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                res=max(res,ans+f(row+1,col1+i,col2+j,grid,dp));
            }
        }
        return dp[row][col1][col2]=res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>>dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return f(0,0,cols-1,grid,dp);
    }
};