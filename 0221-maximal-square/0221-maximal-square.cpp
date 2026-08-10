class Solution {
public:
    int f(int i,int j,vector<vector<char>>& matrix,vector<vector<int>>&dp){
        // if(matrix[i][j]=='0') return 0;
        if(i<0||i>=matrix.size() || j<0||j>=matrix[0].size()) return 0;
        if(matrix[i][j]=='0') return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=f(i,j+1,matrix,dp);
        int down=f(i+1,j,matrix,dp);
        int diag=f(i+1,j+1,matrix,dp);
        int side=1+min(right,min(down,diag));
        return dp[i][j]=side;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans=max(ans,f(i,j,matrix,dp));
            }
        }
        return ans*ans;

        
    }
};