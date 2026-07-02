class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,ans)) return true;
            }
            else if(pathvis[it]){
                return true;
            }
        }
        ans.push_back(node);
        pathvis[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<int> ans;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};