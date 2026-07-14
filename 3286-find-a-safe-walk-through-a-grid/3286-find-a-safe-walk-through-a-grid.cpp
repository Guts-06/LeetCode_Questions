class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows=grid.size();
        int cols=grid[0].size();

        

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dis(rows,vector<int>(cols,INT_MIN));
        dis[0][0]=0;
    
        q.push({health - grid[0][0],{0,0}});
        while(!q.empty()){
            int k=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(k<dis[row][col]) continue;
            for(auto &it:dir){
                int nr=row+it[0];
                int nc=col+it[1];
                if(nr>=0&&nr<=rows-1&&nc>=0&&nc<cols){
                    int newhealth=k-grid[nr][nc];
                    if(newhealth>dis[nr][nc]){
                        q.push({newhealth,{nr,nc}});
                        dis[nr][nc]=newhealth;
                    }
                }
            }

        }
        return dis[rows-1][cols-1]>=1;
    }
};