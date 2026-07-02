class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // while revising see ans variable , how we are checking 4 sides of rotten 
        int rows=grid.size();
        int cols=grid[0].size();
        queue <pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int checkrow[]={-1,0,1,0};
        int checkcol[]={0,-1,0,1};
        int ans=0;
      
        while(!q.empty()){
            int size=q.size();
            while(size){
                auto it=q.front();
                q.pop();
                int row=it .first;
                int col=it.second;
                for(int i=0;i<4;i++){
                    int newrow= row + checkrow[i];
                    int newcol= col+ checkcol[i];
                    if(newrow>=0&&newcol>=0 && newrow<rows&&newcol<cols && grid[newrow][newcol]==1){
                        grid[newrow][newcol]=2;
                        fresh--;
                        q.push({newrow,newcol});
                    }
                }
                size--;
                
            }
        if(!q.empty()) ans++;
        }
        if(fresh) return -1;

        return ans;
    }
};