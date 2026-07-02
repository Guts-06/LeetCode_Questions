class Solution {
public:
    bool dfs(int index , int color , vector<int>&vis,vector<vector<int>> &graph){
        vis[index]=color;
        for(auto it:graph[index]){
            if(vis[it]==-1){
                if(dfs(it,!color,vis,graph)==false) return false;
            }
            else if(vis[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,0,vis,graph)==false) return false;
            }
        }
        return true;
    }
};