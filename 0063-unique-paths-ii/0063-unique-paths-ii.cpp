class Solution {
public:
    int f(vector<vector<int>>& obstacleGrid,int i,int  j,vector<vector<int>>&dp){
        if(i<0||j<0) return 0;
        if(obstacleGrid[i][j]==1)return 0;
        if(i==0&&j==0)return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(obstacleGrid,i,j-1,dp);
        int left=f(obstacleGrid,i-1,j,dp);
        dp[i][j]=up+left;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return f(obstacleGrid,rows-1,cols-1,dp);

    }
};