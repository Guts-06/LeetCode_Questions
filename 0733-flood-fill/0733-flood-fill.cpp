class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size();
        int cols=image[0].size();
        queue<pair<int,int>>q;
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(image[i][j]==color&& i!=sr&&j!=sc){
        //             q.push({i,j});
        //         }
        //     }
        // }
        int original=image[sr][sc];
        if(original==color) return image;
        
        image[sr][sc]=color;
        q.push({sr,sc});
        int checkrow[]={-1,0,1,0};
        int checkcol[]={0,-1,0,1};
        while(!q.empty()){
            int size=q.size();
            while(size){
                auto[row,col]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=row+checkrow[i];
                    int nc=col+checkcol[i];
                    if(nr>=0&&nc>=0&&nr<rows&&nc<cols&&image[nr][nc]==original){
                        image[nr][nc]=color;
                        q.push({nr,nc});
                    }
                }
                size--;
            }
        }
        
        return image;
    }
};