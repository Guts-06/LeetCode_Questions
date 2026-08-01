class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0&&j==0){
            return grid[i][j];
        }
        if(i<0||j<0){
            return 1e8;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int sum_left=grid[i][j]+f(i-1,j,grid,dp);
        int sum_up=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]=min(sum_left,sum_up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return f(rows-1,cols-1,grid,dp);
    }
};