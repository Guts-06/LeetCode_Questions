class Solution {
public:
    bool isCycle(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(isCycle(it,vis,pathvis,adj)==true) return true;
            }
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(isCycle(i,vis,pathvis,adj)==true){
                    return false;
                }
            }

        }
        return true;
    }
};