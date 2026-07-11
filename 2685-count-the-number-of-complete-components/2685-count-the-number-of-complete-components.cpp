class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,int &nodes,int &degree_sum){
        vis[node]=true;
        nodes++;
        degree_sum+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,nodes,degree_sum);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0,degree_sum=0;
                dfs(i,vis,adj,nodes,degree_sum);
                if(nodes*(nodes-1)==degree_sum) ans++;
            }
        }
        return ans;
    }
};