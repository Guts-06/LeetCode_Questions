class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols=grid[0].size();
        int ans=0;
        int checkr[]={-1,0,1,0};
        int checkc[]={0,-1,0,1};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0)continue;

                long long sum=grid[i][j];
                queue<pair<int,int>>q;
                q.push({i,j});
                grid[i][j]=0;

                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nr=row+checkr[i];
                        int nc=col+checkc[i];
                        if(nr>=0 && nr<rows && nc>=0 &&nc<cols&&grid[nr][nc]!=0){
                            q.push({nr,nc});
                            sum+=grid[nr][nc];
                            grid[nr][nc]=0;
                        } 
                    }
                }
                if(sum%k==0)ans++;
            }
        }
        return ans;
    }
};