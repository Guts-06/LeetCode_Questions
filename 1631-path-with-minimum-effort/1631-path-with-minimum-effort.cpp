class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(rows,vector<int>(cols,1e6+1));
        dis[0][0]=0;
        pq.push({dis[0][0],{0,0}});
        int checkrow[]={0,-1,0,1};
        int checkcol[]={-1,0,1,0};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(dist>dis[row][col]) continue; 

            for(int i=0;i<4;i++){
                int nr=row+checkrow[i];
                int nc=col+checkcol[i];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols){
                    int newEffort=max(dist,abs(heights[nr][nc]-heights[row][col]));
                    if(newEffort<dis[nr][nc]){
                        dis[nr][nc]=newEffort;
                        pq.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dis[rows-1][cols-1];
    }
};